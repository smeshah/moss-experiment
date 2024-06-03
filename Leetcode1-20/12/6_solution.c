
  char* intToRoman(int num) {
      char *result = malloc(sizeof(char)*20);//Ã¥ÂÂ Ã§ÂÂº3999 Ã§ÂÂºMMMCMXCIX Ã¦ÂÂÃ¥Â¤Â10Ã¥ÂÂ Ã¤Â½ÂÃ§ÂµÂ¦20Ã¦ÂÂ¯Ã¤Â¿ÂÃ¥Â®Â
      char* roman_symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
      int roman_values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
      int i = 0;

      strcpy(result, ""); 
      while (num > 0) {
          while (num >= roman_values[i]) {
              strcat(result, roman_symbols[i]); 
              num -= roman_values[i]; 
          }
          i++;
      }
      return result;
  }
