

  #define char_to_int(c) ((c) - '0')

  #define MAX(a, b) ((a) > (b)? (a) : (b))

  /**
   * Note: The returned array must be malloced, assume caller calls free().
   */
  char ** letterCombinations(char * digits, int* returnSize)
  {
      char *pad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      int nextSize;

      if (digits[0] == ' ') {
          *returnSize = 0;
          return NULL;
      }

      char c = digits[0];
      int d = char_to_int(c);
      char **next = letterCombinations(digits + 1, &nextSize);
      int i, j, len_digits = strlen(pad[d]);
      char **res;
      res = malloc(sizeof(char *) * len_digits * MAX(1, nextSize));
      *returnSize = 0;

      for (i = 0; i < len_digits; i++) {
          c = pad[d][i];
          if (nextSize == 0) {
              int len = 1 + 1;
              char *s = malloc(len);
              sprintf(s, "%c", c);
              res[*returnSize] = s;
              (*returnSize)++;
          }
          for (j = 0; j < nextSize; j++) {
              int len = strlen(next[j]) + 1 + 1;
              char *s = malloc(len);
              sprintf(s, "%c%s", c, next[j]);
              res[*returnSize] = s;
              (*returnSize)++;
          }
      }

      return res;
  }
