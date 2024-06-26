
  int get_row(int index, int numRows, int modulo) {
      int remainder = index % modulo;
      if (remainder < numRows)
          return remainder;
      return modulo - remainder;
  }

  char* convert(char* s, int numRows) {
      int n = strlen(s);

      int modulo = (numRows < 2) ? numRows : numRows * 2 - 2;

      int max_elem = (n / modulo + 1) * 2 + 1;

      char **solution = malloc(numRows * sizeof(char *));
      int *rows_len = calloc(numRows, sizeof(int));

      for (int i = 0; i < numRows; i++) {
          solution[i] = malloc(max_elem);
      }

      for (int i = 0; i < n; i++) {
          int row = get_row(i, numRows, modulo);
          solution[row][rows_len[row]++] = s[i];
      }

      char *final_sol = malloc(n + 1);
      final_sol[0] = ' ';
      for (int i = 0; i < numRows; i++) {
          solution[i][rows_len[i]] = ' ';
          strncat(final_sol, solution[i], rows_len[i]);
      }
      return final_sol;
  }

