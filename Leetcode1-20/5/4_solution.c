
  #define MAX(a, b)       ((a > b) ? a : b)

  static inline int isPalindrome(register char *p, register char *q) {
      if (p == q) return 1;
      if ((q - p) == 1) return (*p == *q);
      while (p < q) {
          if (*p != *q) return 0;
          p++;
          q--;
      }
      return 1;
  }

  char * longestPalindrome(char * s){
      register char *p = s;
      register int slen = strlen(s);
      register int len = 0;
      register int max_len = 0;
      register int max_index = 0;
      register int i, j;
      if (slen == 1) return s;
      for (i = 0; slen - i > max_len; i++) {
          for (j = slen-1; j - i > max_len; j--) {
              if (s[i] == s[j]) {
                  if (isPalindrome(&s[i], &s[j])) {
                      if (max_len < j-i) {
                          max_len = j-i;
                          max_index = i;
                      }
                  }
              }
          }
      }
      s[max_index+max_len+1] = 0;
      return &s[max_index];
  }
