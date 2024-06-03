
  int comparator(const void *p1, const void *p2) {
      return (*(int *)p1 - *(int *)p2);
  }

  int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
      //First sort array in ascending order for easy operation
      qsort(nums, numsSize, sizeof(int), comparator);
      //Allocate dynamic memory (asked in question itself)
      uint8_t maxSize = 100; // Assuming a maximum of 100 results
      int **result = (int **)malloc(maxSize * sizeof(int *));
      *returnColumnSizes = (int *)malloc(maxSize * sizeof(int));
      *returnSize = 0;

      //take i and j as a fix places
      for (uint8_t i = 0; i < numsSize - 3; i++) {
          if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
          for (uint8_t j = i + 1; j < numsSize - 2; j++) {
              if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates
              //now take two pointers, 1 for most left(excluding i and j positon) and 1 for most right
              uint8_t left = j + 1;
              uint8_t right = numsSize - 1;
              while (left < right) {
                  long int sum = ((long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right]);
                  if (sum == target) {
                      // Store the result
                      result[*returnSize] = (int *)malloc(4 * sizeof(int));
                      (*returnColumnSizes)[*returnSize] = 4;
                      result[*returnSize][0] = nums[i];
                      result[*returnSize][1] = nums[j];
                      result[*returnSize][2] = nums[left];
                      result[*returnSize][3] = nums[right];
                      (*returnSize)++;
                      // Skip duplicates
                      while (left < right && nums[left] == nums[left + 1]) left++;
                      while (left < right && nums[right] == nums[right - 1]) right--;
                      left++;
                      right--;
                  } else if (sum < target) {
                      left++;
                  } else {
                      right--;
                  }
              }
          }
      }
      return result;
  }

