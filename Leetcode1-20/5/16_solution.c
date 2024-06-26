  #define MIN(a,b) ((a)<(b)?(a):(b))

  void preprocess(char *s, char *ss, int len)
  {
      ss[0] = '$';
      ss[len-1] = 0;
      for(int i=1, j=0; i<len; i++)
      {
          if(i&1) ss[i] = '#';
          else 
          {
              ss[i] = s[j];
              j++;
          }
      }
  }

  char* longestPalindrome(char* s) {
      int l = strlen(s);
      if(l<2)
          return s;
      int len = l*2+3;
      char ss[len];
      preprocess(s, ss, len);

      int p[len*2], pivot = 0, max_right = 0;
      memset(p, 0, sizeof(p));
      for(int i=1; i<len-2; i++)
      {

          p[i] = (i<max_right) ? MIN(p[2*pivot-1], max_right-i) : 1;
          while(ss[i+p[i]] == ss[i-p[i]]) p[i]++;
          if(max_right < i+p[i])
          {
              max_right = i+p[i];
              pivot = i;
          }
      }
      int max_count = p[0];
      int max_idx = 0;
      for(int i=1; i<len-2; i++)
      {
          if(max_count < p[i])
          {
              max_count = p[i];
              max_idx = i;
          }
      }
      char *res = (char *)malloc(max_count+1);
      for(int i=max_idx-max_count+1, j=0; i<max_idx+max_count; i++)
      {
          if(ss[i] != '#')
          {
              res[j] = ss[i];
              j++;
          }
      }
      res[max_count-1] = 0;
      return res;
  }
