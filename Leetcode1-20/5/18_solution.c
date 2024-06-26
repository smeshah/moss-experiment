
  #define MIN(x, y) (((x) < (y)) ? (x) : (y))

  void join(char* dst, const char* src, char c ,size_t size)
  {
      if(size == 0)
          return;
      dst[0] = '^';
      size_t i;
      size_t j = 0;
      for( i = 1; i < size-2; ++i)
      {
          if(i%2 == 1)
              dst[i] = c;
          else
              dst[i] = src[j++];
      }
      dst[size-2] = '$';
      dst[size-1] = ' ';
  }

  void substr(char* dst, const char* src, size_t start, size_t end)
  {
      size_t j = 0;
      for(size_t i = start; i <= end; ++i)
          dst[j++] = src[i];
      dst[j] = ' ';
  }

  char * longestPalindrome(char * s){
      if(*s == ' ')
          return "";
      int len_s = strlen(s);

      size_t len_T = 2*len_s+4;
      char* T = (char*)malloc(len_T*sizeof(char));

      char c = '#';
      join(T, s, c, len_T);

      int* P = (int*)malloc(len_T*sizeof(int));
      memset(P, 0, len_T*sizeof(P[0]));

      int R = 0, C = 0;

      for(size_t idx = 1; idx < len_T-1; ++idx)
      {
          if(R > idx)
              P[idx] = MIN(R-idx, P[2*C-idx]);

          while(T[idx-1-P[idx]] == T[idx+1+P[idx]])
              ++P[idx];

          if(idx + P[idx] > R)
          {
              R = idx + P[idx];
              C = idx;
          }
      }

      int maxLen = 0;
      int center = 0;
      for(size_t i = 0; i < len_T; ++i)
      {
          if(maxLen < P[i])
          {
              maxLen = P[i];
              center = i;
          }
      }

      int start = (center-maxLen)/2;
      int end = (center+maxLen)/2-1;
      char* ans = (char*)malloc((end-start+2)*sizeof(s[0]));
      substr(ans, s, start, end);

      return ans;
  }



