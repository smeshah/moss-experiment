

  #define I             1
  #define V             5
  #define X             10
  #define L             50
  #define C             100
  #define D             500
  #define M             1000 
  int romanToInt(char* str) {

      int i = 0; 
      int sum = 0;

      while (str[i])
      {
          if (str[i] == 'C' && str[i + 1] == 'M')
          {
              sum += M-C;
              i+=2;
          }
          else if (str[i] == 'X' && str[i + 1] == 'C')
          {
              sum += C-X;
              i+=2;   
          }
          else if (str[i] == 'X' && str[i + 1] == 'L')
          {
              sum += L-X;
              i+=2;   
          }
          else if (str[i] == 'I' && str[i + 1] == 'V')
          {
              sum += V-I;
              i+=2;
          }
          else if (str[i] == 'I' && str[i + 1] == 'X')
          {
              sum += X-I;
              i+=2;   
          }
          else if (str[i] == 'C' && str[i + 1] == 'D')
          {
              sum += D-C;
              i+=2;   
          }
          else if (str[i] == 'I')
          {
              sum += I;
              i++;
          }
          else if (str[i] == 'V')
          {
              sum += V;
              i++;
          }
          else  if (str[i] == 'X')
          {
              sum += X;
              i++;
          }
          else  if (str[i] == 'L')
          {
              sum += L;
              i++;
          }
          else   if (str[i] == 'C')
          {
              sum += C;
              i++;
          }
          else  if (str[i] == 'D')
          {
              sum += D;
              i++;
          }
          else   if (str[i] == 'M')
          {
              sum += M;
              i++;
          }
      }
      return sum;
  }
