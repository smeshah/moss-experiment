  int romanToInt(char * s)
  {
      int prev = INT_MAX;
      int number = 0;
      while (*s)
      {
          int curr;
          switch (*s)
          {
              case 'I': curr = 1; break;
              case 'V': curr = 5; break;
              case 'X': curr = 10; break;
              case 'L': curr = 50; break;
              case 'C': curr = 100; break;
              case 'D': curr = 500; break;
              case 'M': curr = 1000; break;
          }
          if (prev < curr)
              number += curr - prev * 2;
          else
              number += curr;
          prev = curr;
          s++;
      }

      return number;
  }
