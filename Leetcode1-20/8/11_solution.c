
  #include <inttypes.h>
  #include <stdbool.h>

  bool is_digit(char c)
  {
      return c >= '0' && c <= '9';
  }

  int myAtoi(char * s){
      uint64_t num = 0, max_num;
      int sign = 1;

      for (; *s == ' '; s++)
          ;

      if (*s == '-' || *s == '+') {
          if (*s == '-') {
              sign = -1;
          }
          s++;
      }

      if (sign == -1) {
          max_num = (uint64_t)INT32_MAX + 1;
      } else {
          max_num = (uint64_t)INT32_MAX;
      }

      for (; is_digit(*s); s++) {
          num = num * 10 + (*s - '0');
          if (num > max_num) {
              num = max_num;
              break;
          }
      }

      return num * sign;
  }
