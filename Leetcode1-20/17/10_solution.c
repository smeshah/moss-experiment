

  char *str[10] = {"abc", "def",
                   "ghi", "jkl", "mno",
                   "pqrs", "tuv", "wxyz"};

  void __add(int nums, int *count, char ***ret, char *tmp)
  {
          char *p = malloc(sizeof(char) * (nums + 1));

          int i;
          while (tmp[i]) {
                  p[i] = tmp[i];
                  i++;
          }
          p[i] = tmp[i];

          (*ret)[(*count)++] = p;
  }

  void add(char **p, int nums, int cur_num, int *count, char ***ret, char *tmp)
  {
          if (cur_num == nums) {
                  tmp[cur_num] = ' ';
                  __add(nums, count, ret, tmp);
                  return;
          }

          int i = 0;
          while (p[cur_num][i]) {
                  tmp[cur_num] = p[cur_num][i];
                  add(p, nums, cur_num + 1, count, ret, tmp);
                  i++;
          }
  }

  char **letterCombinations(char * digits, int* returnSize)
  {
          int dn, size;
          char *p0;
          char *p[4];

          if (!*digits) {
                  *returnSize = 0;
                  return NULL;
          }

          size = 1;
          dn = 0;
          int i = 0;
          while (digits[i]) {
                  dn++;
                  size *= 4;
                  p[i] = str[digits[i] - '2'];
                  i++;
          }

          char **ret = malloc(sizeof(char *) * size);
          int count = 0;
          char tmp[5] = {0};
          add(p, dn, 0, &count, &ret, tmp);

          *returnSize = count;
          return ret;
  }
