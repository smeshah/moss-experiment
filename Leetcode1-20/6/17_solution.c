
  char *convert(char *s, int numRows){

      if (numRows == 1)
          return s;

      int k,
          len_s = strlen(s),
          *indexes = (int *)malloc((len_s) * sizeof(int));
      char *result = (char *)malloc((len_s + 1) * sizeof(char));

      k = 0;

      while (k < len_s)
      {
          for (int i = 0; i < numRows; i++)
          {
              if (k == len_s)
                  break;
              indexes[k] = i;
              k++;
          }

          for (int j = numRows - 2; j >= 1; j--)
          {
              if (k == len_s)
                  break;
              indexes[k] = j;
              k++;
          }
      }

      k = 0;

      for (int i = 0; i < numRows; i++)
      {
          for (int j = 0; j < len_s; j++)
          {
              if (indexes[j] == i)
              {
                  result[k] = s[j];
                  k++;
              }
          }
      }

      result[k] = ' ';

      return result;
  }
