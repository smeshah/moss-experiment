
  char* longestCommonPrefix(char** strs, int strsSize) {
      printf("%d",strsSize);
      printf("%s",strs);
      if (strsSize == 0) return "";
      if (strsSize == 1) return strs[0];

      int count = 0;
      char *str = NULL;

      do {
          for (int i = 1; i < strsSize; i++) {
              if (strs[i][count] != strs[0][count] || strs[i][count] == ' ') {
                  if (count == 0) return ""; 
                  str = (char *)malloc((count + 1) * sizeof(char)); 
                  if (str == NULL) return ""; 
                  strncpy(str, strs[0], count); 
                  str[count] = ' '; 
                  return str;
              }
          }
          count++;
      } while (strs[0][count] != ' ');



      str = (char *)malloc((count + 1) * sizeof(char));
      if (str == NULL) return ""; 
      strncpy(str, strs[0], count);
      str[count] = ' '; 
      return str;
  }


