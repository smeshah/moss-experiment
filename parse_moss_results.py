import os
import requests
import argparse
from bs4 import BeautifulSoup

def download_html(url, output_path):
    response = requests.get(url)
    if response.status_code == 200:
        with open(output_path, 'w') as file:
            file.write(response.text)
        return True
    return False

def parse_moss_results(html_path, url, threshold):
    with open(html_path, 'r') as file:
        soup = BeautifulSoup(file, 'html.parser')

    matching_records = []

    for row in soup.find_all('tr')[1:]:  # Skip the header row
        cols = row.find_all('td')
        if len(cols) > 1:
            file1_info = cols[0].find('a').text
            file2_info = cols[1].find('a').text

            # Extract percentages
            match_percentage1 = int(file1_info.split('(')[-1].strip('%)'))
            match_percentage2 = int(file2_info.split('(')[-1].strip('%)'))
            
            # Use the higher percentage for comparison
            match_percentage = max(match_percentage1, match_percentage2)
            
            if match_percentage > threshold:
                record = {
                    'file1': file1_info,
                    'file2': file2_info,
                    'percentage': match_percentage,
                    'url': cols[1].find('a')['href']
                }
                matching_records.append(record)
    
    return matching_records

def main(base_dir, threshold):
    all_matching_records = []

    for subdir, _, files in os.walk(base_dir):
        try:
            if 'results.txt' in files:
                with open(os.path.join(subdir, 'results.txt'), 'r') as f:
                    lines = f.readlines()
                    if lines:
                        url = lines[-1].strip()
                        html_path = os.path.join(subdir, 'index.html')
                        
                        if download_html(url, html_path):
                            matching_records = parse_moss_results(html_path, url, threshold)
                            all_matching_records.extend(matching_records)
                        else:
                            print(f"Failed to download HTML from {url}")
        except:
            continue

    # Write results to an HTML file
    output_html = os.path.join('matching_results.html')
    with open(output_html, 'w') as f:
        f.write('<html><head><title>MOSS Results</title></head><body>')
        f.write('<h1>MOSS Matching Results</h1>')
        f.write(f'<h3>Threshold Percentage: {threshold}%</h3>')

        f.write('<table border="1"><tr><th>File 1</th><th>File 2</th><th>Matching Percentage</th><th>Details</th></tr>')

        for record in all_matching_records:
            f.write(f'<tr>')
            f.write(f'<td>{record["file1"]}</td>')
            f.write(f'<td>{record["file2"]}</td>')
            f.write(f'<td>{record["percentage"]}%</td>')
            f.write(f'<td><a href="{record["url"]}">View Details</a></td>')
            f.write(f'</tr>')

        f.write('</table></body></html>')

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Process Moss results.")
    parser.add_argument("base_dir", type=str, help="Base directory for Moss results")
    parser.add_argument("threshold", type=int, help="Threshold value")
    args = parser.parse_args()
    main(args.base_dir, args.threshold)