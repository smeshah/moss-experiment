
  int strl_len(char *s)
  {
      int i = 0;
      while(s[i] != 0)
      {
          i++;
      }
      return i;
  }

  int check_palindrom(char* s, int min, int max)
  {
      int len = max - min + 1;

      for(int i = 0; i <= len / 2; i++)
      {
          if(s[min + i] != s[max - i])
          {
              return 0;
          }
      }

      return 1;
  }


  char * longestPalindrome(char * s){
      int curr_longest = 0;
      int min_l = 0;
      int max_l = 0;

      int length = strl_len(s);
      for(int i = 0; i < length; i++)
      {
          for(int j = i + 1; j < length; j++)
          {
              //don't need to search a palindrom if it couldn't be the longest anyway
              if(j - i  + 1 > curr_longest && s[j] == s[i])
              {
                  int res = check_palindrom(s, i, j);
                  if(res)
                  {
                      curr_longest = j - i + 1;
                      min_l = i;
                      max_l = j;
                  }
              }
          }
      }

      char* res = (char*)malloc((length + 1) * sizeof(char));

      int j = 0;
      for(int i = min_l; i <= max_l; i++)
      {
          res[j++] = s[i];
      }
      res[j] = 0;

      return res;
  }
