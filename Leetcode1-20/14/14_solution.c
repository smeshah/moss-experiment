
  char* longestCommonPrefix(char** strs, int strsSize) {
      int i = 0, j, state = 1;
      char *fin, temp;
      fin = malloc(50);
      while (state == 1){
          temp = strs[0][i];
          for(j = 0; j<strsSize; j++){
              if(temp == strs[j][i])
                  state = 1;
              else {
                  state = 0;
                  break;
              }
          }
          if (state == 0)
              break;
          else {
              fin[i++] = temp;
          }
      }
      return fin;
  }
