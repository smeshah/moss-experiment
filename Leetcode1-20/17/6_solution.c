
  /**
   * Note: The returned array must be malloced, assume caller calls free().
   */

  char two[4] = {'a','b','c',' '};
  char three[4] = {'d','e','f',' '};
  char four[4] = {'g','h','i',' '};
  char five[4] = {'j','k','l',' '};
  char six[4] = {'m','n','o',' '};
  char seven[5] = {'p','q','r','s',' '};
  char eight[4] = {'t','u','v',' '};
  char nine[5] = {'w','x','y','z',' '};

  char* match(char c)
  {
    char* key;
    if(c == '2')
      key = two;
    else if(c == '3')
      key = three;
    else if(c == '4')
      key = four;
    else if(c == '5')
      key = five;
    else if(c == '6')
      key = six;
    else if(c == '7')
      key = seven;
    else if(c == '8')
      key = eight;
    else
      key = nine;
    return key;
  }

  void builder(char* digits,char** ans, int* size, char* data, int curr_index)
  {
    if(!digits[curr_index])
    {
      int ret_size = curr_index + 1;
      data[curr_index] = ' ';
      ans[(*size)] = (char*)malloc(ret_size * sizeof(char));
      memcpy(ans[(*size)], data, ret_size * sizeof(char));
      (*size)++;
      return;
    }
    char* candidate = match(digits[curr_index]);
    int counter;
    int next_index = curr_index + 1;
    for(counter = 0;candidate[counter];counter++)
    {
      data[curr_index] = candidate[counter];
      builder(digits, ans, size, data, next_index);
    }
    return;
  }

  char ** letterCombinations(char * digits, int* returnSize){
    if(!digits[0])
    {
      char** ans = (char**)calloc(0, sizeof(char*));
      *returnSize = 0;
      return ans;
    }
    char** ans = (char**)calloc(10000, sizeof(char*));
    char* data = (char*)malloc(6 * sizeof(char));
    int size = 0;
    int* pointer = &size;
    builder(digits, ans, pointer, data, 0);
    *returnSize = size;
    return ans;
  }
