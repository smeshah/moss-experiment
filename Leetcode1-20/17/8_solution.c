
  /**
   * Note: The returned array must be malloced, assume caller calls free().
   */


  char* dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  void combine(char* digits, int index, char* combination, char** results, int* result_count) {
      if (digits[index] == ' ') {
          //Ã¨Â·ÂÃ¥Â®ÂdigitsÃ¦ÂÂÃ¦ÂÂÃ§ÂÂÃ¦ÂÂ¸Ã¥Â­Â Ã¦ÂÂÃ¦ÂÂÃ©ÂÂ²Ã¤Â¾Â
          //Ã¥Â°ÂÃ§ÂÂ®Ã¥ÂÂÃ§ÂÂÃ§ÂµÂÃ¥ÂÂÃ¥ÂÂÃ¤Â½ÂµÃ¨ÂµÂ·Ã¤Â¾Â
          results[*result_count] = strdup(combination);
          (*result_count)++;
          return;
      }

      char* letters = dict[digits[index] - '0'];//Ã¨Â½ÂÃ¦ÂÂÃ¥Â°ÂÃ¦ÂÂÃ§ÂÂÃ¦ÂÂ¸Ã¥Â­ÂÃ¥ÂÂ¼
      for (int i = 0; i < strlen(letters); i++) {
          //Ã¦ÂÂ¾dictÃ§ÂÂÃ¦ÂÂÃ¦ÂÂÃ¥Â­ÂÃ¦Â¯Â
          combination[index] = letters[i];
          combine(digits, index + 1, combination, results, result_count); //Ã§ÂÂ¢Ã§ÂÂÃ¦ÂÂÃ¦ÂÂÃ¥ÂÂ¯Ã¨ÂÂ½Ã§ÂÂÃ§ÂµÂÃ¥ÂÂ
          //Ã©ÂÂÃ©ÂÂ+1Ã¦ÂÂ¯Ã§ÂÂºÃ¤ÂºÂ
          //Ã¥ÂÂÃ¨Â¨Â­Ã¤Â»ÂÃ¥Â¤Â©Ã¨Â¼Â¸Ã¥Â    Â¥digits = "23"
          //Ã©ÂÂ£Ã¥Â°Â±Ã¦ÂÂÃ¥Â    ÂÃ¥ÂÂ·Ã¨Â¡Âa
          //Ã©ÂÂ²Ã¤Â¾ÂÃ¨Â¿Â´Ã¥ÂÂÃ©ÂÂÃ¥Â§ÂÃ¨Â·Â 3 Ã§ÂÂ e f g
          //Ã¨Â·ÂÃ¥Â®ÂÃ¦ÂÂÃ¦ÂÂ b
          //Ã©ÂÂ²Ã¤Â¾ÂÃ¨Â¿Â´Ã¥ÂÂÃ©ÂÂÃ¥Â§ÂÃ¨Â·Â 3 Ã§ÂÂ e f g
          //Ã¦ÂÂÃ¥Â¾ÂÃ§ÂÂºC
          //Ã©ÂÂ²Ã¤Â¾ÂÃ¨Â¿Â´Ã¥ÂÂÃ©ÂÂÃ¥Â§ÂÃ¨Â·Â 3 Ã§ÂÂ e f g
      }
  }

  char** letterCombinations(char* digits, int* returnSize) {
      if (digits == NULL || *digits == ' ') {
          *returnSize = 0;
          return NULL;
      }

      int num_digits = strlen(digits);
      int total_combinations = 1;
      for (int i = 0; i < num_digits; i++) {
          total_combinations *= strlen(dict[digits[i] - '0']);//Ã¥ÂÂ Ã§ÂÂºdigitsÃ¦ÂÂ¯Ã¥Â­ÂÃ¥Â    Â Ã©ÂÂÃ©ÂÂ-'0' Ã¥Â°Â±Ã¥ÂÂ¯Ã¤Â»Â¥Ã¥Â¾ÂÃ¥ÂÂ°Ã¥Â­ÂÃ¥Â    ÂÃ¨Â½ÂÃ¦ÂÂÃ¦ÂÂ¸Ã¥Â­Â
      }

      char** results = (char**)malloc(total_combinations * sizeof(char*));
      char* combination = (char*)malloc((num_digits + 1) * sizeof(char));
      *returnSize = 0;

      combination[num_digits] = ' ';
      combine(digits, 0, combination, results, returnSize);
      free(combination);
      return results;
  }


