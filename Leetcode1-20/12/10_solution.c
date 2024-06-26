

  #define LOG(x) if (0) printf("%d ", x)
  char *roman_helper(char *buf, uint32_t count, char ten, char five, char one) {
      while (count) {
          if (count == 9) {
              LOG(11);
              buf += sprintf(buf, "%c%c", one, ten);
              count -= 9;
          } else if (count >=5) {
              count -= 5;
              LOG(12);
              buf += sprintf(buf, "%c", five);
          } else if (count >= 4) {
              count -= 4;
              LOG(13);
              buf += sprintf(buf, "%c%c", one, five);
          } else if (count) {
              LOG(14);
              for (int i = 0; i < count; i++) {
                  LOG(15);
                  buf += sprintf(buf, "%c", one);
              }
              count = 0;
          }
      }
      return buf;
  }

  char * intToRoman(int num){
      /* helper to find the size of the returned number */
      int roman_size(int div_c[]) {
          const uint8_t roman_char_size[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
          int size = 0;
          /* 1000s */
          size += div_c[0];
          for (int i = 1; i < 4; i++)
              size += roman_char_size[div_c[i]];
          return size;
      }

      int div_c [] = {0, 0, 0, 0};
      int div_idx = 0;
      int divisor = 1000;
      while (num != 0) {
         int div = num / divisor;
         int rem = num % divisor;
         div_c[div_idx++] = div;
         num = rem;
         divisor = divisor / 10;
      }
      LOG(1);
      int size = roman_size(div_c);
      LOG(size);
      char  *output = calloc(1, size+1); 
      char *cp = output;
      for (int i = 0; i < div_c[0]; i++)
          cp += sprintf(cp, "%c", 'M');
      LOG(2);
      cp = roman_helper(cp, div_c[1], 'M', 'D', 'C' );
      LOG(3);
      cp = roman_helper(cp, div_c[2], 'C', 'L', 'X' );
      LOG(4);
      cp = roman_helper(cp, div_c[3], 'X', 'V', 'I' );
      LOG(5);
      return output;
  }
