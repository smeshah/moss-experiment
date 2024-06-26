
  #include <math.h>

  void dp(int num, char romanNums[][100]){
      // dynamic programming
      int power = 0;
      int base = 0;
      int temp = 0;
      char res[100] = {' '};
      char* pRes = res;

      if (romanNums[num][0])
          return;

      else{
          power = (int)log10(num);
          base = pow(10, power);
          if (!(num % base)){ // num is the most significant digit followed by zeros
              if (num > 5 * base){
                  temp = num - 5 * base;
                  strcat(pRes, romanNums[5 * base]);
                  pRes += strlen(romanNums[5 * base]);
              }
              else
                  temp = num;

              while(temp){
                  strcat(pRes, romanNums[base]);
                  pRes += strlen(romanNums[base]);
                  temp -= base;
              }
              strcpy(romanNums[num], res);
              return;
          }
          else{
              dp(num - num % base, romanNums);
              strcpy(res, romanNums[num - num % base]);
              pRes += strlen(res);
              dp(num % base, romanNums);
              strcat(pRes, romanNums[num % base]);
              strcpy(romanNums[num], res);
              return;
          }
      }

  }

  char* intToRoman(int num) {
      // initialize a hashtable. Must be static
      static char romanNums[4000][100] = {{' '}};
      strcpy(romanNums[1], "I");
      strcpy(romanNums[4], "IV");
      strcpy(romanNums[5], "V");
      strcpy(romanNums[9], "IX");
      strcpy(romanNums[10], "X");
      strcpy(romanNums[40], "XL");
      strcpy(romanNums[50], "L");
      strcpy(romanNums[90], "XC");
      strcpy(romanNums[100], "C");
      strcpy(romanNums[400], "CD");
      strcpy(romanNums[500], "D");
      strcpy(romanNums[900], "CM");
      strcpy(romanNums[1000], "M");

      dp(num, romanNums);

      return romanNums[num];


  }
