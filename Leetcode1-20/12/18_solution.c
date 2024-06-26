
  #define BUFF_SIZE (16)

  char * intToRoman(int num)
  {
      char * res = malloc((BUFF_SIZE + 1) * sizeof(char)); // + 1 for EOS char
      res[BUFF_SIZE] = ' ';
      int i = BUFF_SIZE - 1;
      char rs[][3] = {{'I','V','X'}, {'X','L','C'}, {'C','D','M'}, {'M','M','M'}};

      for (int j = 0; num > 0; j++)
      {
          switch (num % 10)
          {
              case 0:
                  break;
              case 3:
                  res[i--] = rs[j][0];
              case 2:
                  res[i--] = rs[j][0];
              case 1:
                  res[i--] = rs[j][0];
                  break;
              case 4:
                  res[i--] = rs[j][1];
                  res[i--] = rs[j][0];
                  break;
              case 8:
                  res[i--] = rs[j][0];
              case 7:
                  res[i--] = rs[j][0];
              case 6:
                  res[i--] = rs[j][0];
              case 5:
                  res[i--] = rs[j][1];
                  break;
              case 9:
                  res[i--] = rs[j][2];
                  res[i--] = rs[j][0];
          }

          num = num / 10;
      }

      i++;
      memcpy(res, &res[i], BUFF_SIZE-i+1);
      return res;
  }
