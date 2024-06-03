
  int compare(const void* a, const void* b) {
      return (*(int*)a - *(int*)b);
  }

  int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
      qsort(nums, numsSize, sizeof(int), compare);

      *returnSize = 0;
      int capacity = 16;
      int** result = (int**)malloc(sizeof(int*) * capacity);
      *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

      for (int i = 0; i < numsSize - 2; i++) {
          if (i == 0 || nums[i] != nums[i - 1]) {
              int left = i + 1;
              int right = numsSize - 1;
              while (left < right) {
                  int sum = nums[i] + nums[left] + nums[right];
                  if (sum == 0) {
                      if (*returnSize >= capacity) {

                          capacity *= 2;
                          result = realloc(result, sizeof(int*) * capacity);
                          *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * capacity);
                      }

                      result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                      (*returnColumnSizes)[*returnSize] = 3;
                      result[*returnSize][0] = nums[i];
                      result[*returnSize][1] = nums[left];
                      result[*returnSize][2] = nums[right];
                      (*returnSize)++;

                      while (left < right && nums[left] == nums[left + 1]) left++;
                      while (left < right && nums[right] == nums[right - 1]) right--;

                      left++;
                      right--;
                  } else if (sum < 0) {
                      left++;
                  } else {
                      right--;
                  }
              }
          }
      }

      result = realloc(result, sizeof(int*) * (*returnSize));
      *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));

      return result;
  }

