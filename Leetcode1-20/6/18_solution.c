  char* convert(char* s, int numRows) {
      if (numRows == 1) {
          return s;
      }
      int len = strlen(s);
      char *buf = (char *) malloc(sizeof(char) * (len + 1));
      int i = 0;
      for (int row = 0; row < numRows; row++) {
          int step = (numRows - 1) * 2;
          int j = 0;
          while (j + row < len) {
              buf[i++] = s[j + row];
              j += step;
              if (row > 0 && row < numRows - 1 && j - row < len) {
                  buf[i++] = s[j - row];
              }
          }
      }
      buf[len] = ' ';
      return buf;
  }
