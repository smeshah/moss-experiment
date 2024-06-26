
  char* longestCommonPrefix(char** strs, int strsSize) 
  {
      char c;
      char ret[5];
      unsigned int lCount = 0;
      unsigned int stop = 0;

      memset(ret, 0, strlen(ret));

      while(stop != 1)
      {
          c = strs[0][lCount];

          for(unsigned int j = 0; j < strsSize; j++)
          {
              if(lCount >= strlen(strs[j]) || strs[j][lCount] != c)
              {
                  stop = 1;
                  break;
              }
          }

          if(stop == 1)
              break;

          lCount++;
      } 

      if(lCount == 0)
          return "";

      char* result = malloc(lCount+1);
      strncpy(result, strs[0], lCount);
      result[lCount] = ' ';

      return result;
  }
