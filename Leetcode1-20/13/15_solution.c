
  int DecimalNumericalPlace(char roman_np_value)
  {
          switch (roman_np_value) {
                  case 'I':
                          return 1;
                          break;

                  case 'V':
                          return 5;
                          break;

                  case 'X':
                          return 10;
                          break;

                  case 'L':
                          return 50;
                          break;

                  case 'C':
                          return 100;
                          break;

                  case 'D':
                          return 500;
                          break;

                  case 'M':
                          return 1000;
                          break;

                  default:
                          return -1;
          }
  }

  int RomanToInt(char *roman_num)
  {
          int num, current, next, len;

          num = 0;
          len = strlen(roman_num);
          for (int i = 0; i < len; i++) {
                  current = DecimalNumericalPlace(roman_num[i]);
                  next = DecimalNumericalPlace(roman_num[i + 1]);
                  if (current < next)
                          num -= current;
                  else
                          num += current;
          }

          return num;
  }
