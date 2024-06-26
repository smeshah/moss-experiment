
  char *ltrim(char *s)
  {
      while (*s) {
          if (isspace(*s))
              s++;
          else
              break;
      }
      return s;
  }

  void rtrim(char *s)
  {
      // go to the end
      char *end = s;
      while (*end) {
          if (*(end + 1) == ' ')
              break;
          end++;
      }

      while (*end && end >= s) {
          if (isspace(*end) || isalpha(*end)) {
              *end = ' ';
              end--;
          } else
              break;
      }
  }

  int myAtoi(char * str)
  {
      if (strlen(str) > 0 && isalpha(str[0]))
          return 0;

      str = ltrim(str);

      if (strlen(str) == 0)
          return 0;

      rtrim(str);    

      if (strlen(str) == 0)
          return 0;

      if (isalpha(str[0]))
          return 0;

      bool positive = str[0] != '-';

      if (str[0] == '+') {
          positive = true;
          str++;
      }

      if (!positive)
          str++;

      if (strlen(str) == 0)
          return 0;

      if (!isdigit(str[0]))
          return 0;

      while (*str) {
          if (*str == '0')
              str++;
          else
              break;
      }

      int len = strlen(str);
      if (len == 0)
          return 0;

      int i;
      long long n = 0, power = 1;

      for (i = len - 1; i >= 0; i--) {
          if (!isdigit(str[i])) {
              n = 0;
              power = 1UL;
          } else {
              if (positive && (n > INT_MAX || power > INT_MAX))
                  return INT_MAX;
              if (!positive && (n < INT_MIN || power > INT_MAX))
                  return INT_MIN;
              n += power * (str[i] - '0');
              power *= 10UL;
          }
      }

      if (!positive)
          n = -n;

      if (positive && n > INT_MAX)
          n = INT_MAX;
      if (!positive && n < INT_MIN)
          n = INT_MIN;

      return n;
  }
