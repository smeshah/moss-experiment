
  int romanToInt(char * s)
  {
      int I = 1;
      int V = 5;
      int X = 10;
      int L = 50;
      int C = 100;
      int D = 500;
      int M = 1000;
      int sum = 0;
      int i = 0;
      while (s[i])
      {
          if (s[i] == 'C' && s[i + 1] == 'M')
          {
              i += 2;
              sum += (D + 4 * C);
          }
          else if (s[i] == 'X' && s[i + 1] == 'C')
          {
              i += 2;
              sum += (L + 4 * X);
          }
          else if (s[i] == 'I' && s[i + 1] == 'X')
          {
              i += 2;
              sum += (V + 4 * I); 
          }
          else if (s[i] == 'C' && s[i + 1] == 'D')
          {
              i += 2;
              sum += 4 * C;
          }
          else if (s[i] == 'X' && s[i + 1] == 'L')
          {
              i += 2;
              sum += 4 * X; 
          }
          else if (s[i] == 'I' && s[i + 1] == 'V')
          {
              i += 2;
              sum += 4 * I; 
          }
          else if (s[i] == 'I')
          {
              sum += I;
              i++;
          }    
          else if (s[i] == 'V')
          {
              sum += V;
              i++;
          }
          else if (s[i] == 'X')
          {
              sum += X;
              i++;
          }
          else if (s[i] == 'L')
          {
              sum += L;
              i++;
          }
          else if (s[i] == 'C')
          {
              sum += C;
              i++;
          }
          else if (s[i] == 'D')
          {
              sum += D;
              i++;
          }
          else if (s[i] == 'M')
          {
              sum += M;
              i++;
          }  
      }
      return sum;
  }
