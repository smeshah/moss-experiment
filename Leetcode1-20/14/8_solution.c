
  char * longestCommonPrefix(char ** strs, int strsSize){
      static char ans[999];
      strcpy(ans, strs[0]);
      if(strsSize == 1){
          return ans;
      }
      for(int i = 1; i < strsSize; i++){
          char temp[999] = "";
          int c = 0;
          for(int j = 0; j < strlen(ans); j++){
              if(ans[j] == strs[i][j]){
                  temp[c] = strs[i][j];
                  c++;
              } else{
                  break;
              }
          }
          strcpy(ans, temp);
      }
      return ans;
  }
