
  /**
   * Note: The returned array must be malloced, assume caller calls free().
   */
  void generate(char map[10][5], char* digits, int idx, int len, int* returnSize, char **res, char *cur_str) {
      if (idx == len) {
          res[*returnSize] = strdup(cur_str);
          *returnSize += 1;
          return;
      }
      int x = digits[idx]-'0';
      for (int i = 0; i < strlen(map[x]); i++) {
          cur_str[idx] = map[x][i];
          generate(map, digits, idx+1, len, returnSize, res, cur_str);
      }
  }

  char** letterCombinations(char* digits, int* returnSize) {
      int n = strlen(digits);
      *returnSize = 0;
      if (!n) return NULL;
      char map[10][5] = {
          "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
      };
      char **res = (char**)malloc(pow(4,n)*sizeof(char*));
      char cur_str[n+1];
      cur_str[n] = ' ';
      generate(map, digits, 0, n, returnSize, res, cur_str);
      res = (char**)realloc(res, sizeof(char*)*(*returnSize));

      return res;
  }
