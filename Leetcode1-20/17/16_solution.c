

    int is_four_digit(char *digits, int index) {
        return digits[index] == '9' || digits[index] == '7';
    }

    int should_increase(char *digits, int index, int *digit_map) {
        if (is_four_digit(digits, index)) {
            return digit_map[index] >= 4;
        } else {
            return digit_map[index] >= 3;
        }
    }

    /**
     * Note: The returned array must be malloced, assume caller calls free().
     */
    char ** letterCombinations(char * digits, int* returnSize){

        int digit_len = 0;
        int *digit_map;
        char **result;
        char char_map[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int nine_count = 0;
        int increase_digit = 0;

        if (digits[0] == 0) {
            *returnSize = 0;
            return result;
        }

        if (is_four_digit(digits, 0)) {
            *returnSize = 4;
        } else {
            *returnSize = 3;
        }

        digit_len++;

        for (int i = 1; digits[i] != 0; i++) {
            if (is_four_digit(digits, i)) {
                *returnSize *= 4;
            } else {
                *returnSize *= 3;
            }
            digit_len++;
        }

        digit_map = calloc(digit_len, sizeof(int));


        result = calloc(*returnSize, sizeof(char*));

        for (int i = 0; i < *returnSize; i++) {
            result[i] = calloc(digit_len + 1, sizeof(char));
        }

        for (int i = 0; i < *returnSize; i++) {
            for (int j = 0; j < digit_len; j++) {
                result[i][j] = char_map[digits[j] - '0'][digit_map[j]];
            }

            result[i][digit_len] = 0;

            for (int j = digit_len - 1; j >= 0; j--) {
                if (j == digit_len - 1) {
                    digit_map[j]++;
                } else if (increase_digit) {
                    digit_map[j]++;
                }

                if (should_increase(digits, j, digit_map)) {
                    digit_map[j] = 0;
                    increase_digit = 1;
                } else {
                    increase_digit = 0;
                }
            }
        }

        for (int i = 0; i < *returnSize; i++) {
            printf("%s
  ", result[i]);
        }

        return result;
    }
