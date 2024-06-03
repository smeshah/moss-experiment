
  int myAtoi(char *str) {
      int idx = 0;
      int sign = 1;
      long result = 0; 

      while(str[idx] == ' ') {
          idx++;
      }

      if(str[idx] == '-' || str[idx] == '+') {
          if(str[idx] == '-') sign = -1;
          else sign = 1;
          idx++;
      }

      while(str[idx] >= '0' && str[idx] <= '9') {
          result = result * 10 + (str[idx] - '0');
          if(sign * result > INT_MAX) return INT_MAX;
          if(sign * result < INT_MIN) return INT_MIN;
          idx++;
      }
      return (int)(sign * result);
  }

  // int myAtoi(char* s) {
  //     char *endptr;
  //     long num = strtol(s, &endptr, 10);
  //     if (num > INT_MAX) return INT_MAX;
  //     if (num < INT_MIN) return INT_MIN;
  //     return num;
  // }
