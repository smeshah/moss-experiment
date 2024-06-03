
  /*
      I (73) - 67 = 6
      V (86) - 67 = 19
      X (88) - 67 = 21
      L (76) - 67 = 9
      C (67) - 67 = 0
      D (68) - 67 = 1
      M (77) - 67 = 10
  */

  #define ROMAN_CHECK(x) (roman_lut[x - 67])

  const static int roman_lut[22] = {100, 500, 0, 0,  0,
                                      0,   1, 0, 0, 50,
                                   1000,   0, 0, 0,  0,
                                      0,   0, 0, 0,  5,
                                      0, 10};

  int romanToInt(char * s){
      int result = 0;
      int previous_value = 1001;
      int current_value = 0;

      for(int i  = 0; s[i]; i++)
      {
          current_value = ROMAN_CHECK(s[i]);
          if(previous_value < current_value)
          {
              int new = current_value - previous_value;
              result = (result - previous_value) + new;
          }
          else result += current_value;
          previous_value = current_value;
      }
      return result;
  }
