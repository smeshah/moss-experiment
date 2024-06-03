
  int str_len(char* s)
  {
      int len = 0;
      while(s[len] != 0)
      {
          len++;
      }

      return len;
  }

  char * convert(char * s, int numRows){
      int len = str_len(s);
      char* res = (char*)malloc(len * sizeof(char) + 1);

      int a = 0;
      int b = numRows * 2 - 2 > 0 ? numRows * 2 - 2: 1;
      int count = 0;

      for(int i = 0; i < numRows; i++)
      {
          int j = i;

          int change = 0;
          while(j < len)
          {
              res[count++] = s[j];

              if(change && a != 0 || !b)
              {
                  j += a;
                  change = 0;
              }
              else
              {
                  j += b;
                  change = 1;
              }
          }

          a+=2;
          b-=2;
      }
      res[count] = 0;

      return res;
  }
