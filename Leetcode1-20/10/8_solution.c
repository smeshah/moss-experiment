
  bool isMatch(char* s, char* p) {
  	int i = 0, j = 0;
  	while (i < strlen(s) && j < strlen(p))
  	{
  		if (j != strlen(p) - 1 && p[j + 1] == '*') {
  			while (s[i] == p[j] || p[j]=='.') {
  				bool is_worth_ignore = isMatch(s + i, p + j + 2);
  				if (is_worth_ignore) return true;
  				i++;
                  if (i == strlen(s)) break;
  			}
  			j += 2;
  		}
  		else if (p[j] == '.') {
  			i++;
  			j++;
  		}
  		else if (p[j] != s[i]) return false;
  		else {
  			i++;
  			j++;
  		}
  	}
  	while (j < strlen(p)) {
  		if (p[j + 1] == '*') j += 2;
  		else break;
  	}
  	if (i != strlen(s) || j != strlen(p)) return false;
  	return true;
  }
