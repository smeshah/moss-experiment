
  char * intToRoman(int num){

      int i, j, k;
      i, j = k = 0;
      const int   c[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
      const char *v[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
  	               "V", "IV", "I"};
      char buf[16] = {0};
      char *ptr;

      while (num) {
          while (num >= c[j]) {
              num -= c[j];
              k++;
          }
          if (k)
  		    while (k--)
                  strcat(buf, v[j]);

          k = 0;
          j++;
      }
      i = strlen(buf);
      ptr = malloc(i+1);
      strcpy(ptr, buf);
      ptr[i] = 0;
      return ptr;
  }
