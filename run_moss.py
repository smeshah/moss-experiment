import os
import subprocess
import argparse

def run_moss(base_dir, output_base_dir):
    # Create the base directory for the results
    os.makedirs(output_base_dir, exist_ok=True)

    # Iterate over all subdirectories in the base directory
    for subdir in os.listdir(base_dir):
        dir_path = os.path.join(base_dir, subdir)
        
        # Check if it's a directory
        if os.path.isdir(dir_path):
            # Create a corresponding directory in the output base directory
            output_dir = os.path.join(output_base_dir, subdir)
            os.makedirs(output_dir, exist_ok=True)
            
            # Check if there are any .c files in the subdirectory
            c_files = [f for f in os.listdir(dir_path) if f.endswith('.c')]
            if c_files:
                print(f"Running moss.pl for directory: {dir_path}")
                
                # Run moss.pl and save the output to a text file in the output directory
                moss_command = ["sudo", "perl", "./moss.pl", "-l", "c"] + [os.path.join(dir_path, f) for f in c_files]
                with open(os.path.join(output_dir, "results.txt"), "w") as output_file:
                    subprocess.run(moss_command, stdout=output_file)
            else:
                print(f"No .c files found in directory: {dir_path}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Run MOSS analysis')
    parser.add_argument('base_dir', metavar='<base_dir>', type=str,
                        help='The base directory containing source files')
    parser.add_argument('output_base_dir', metavar='<output_base_dir>', type=str,
                        help='The output base directory for MOSS results')
    
    args = parser.parse_args()
    run_moss(args.base_dir, args.output_base_dir)