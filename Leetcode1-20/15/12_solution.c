
  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  // Function to compare integers for qsort
  int compare(const void *a, const void *b) {
      return (*(int *)a - *(int *)b);
  }

  // Function to check if the sum of three elements is zero
  int isSumZero(int a, int b, int c) {
      return (a + b + c == 0);
  }

  // Function to find all unique triplets with sum zero
  int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
      // Sorting the array is essential for handling duplicates efficiently
      qsort(nums, numsSize, sizeof(int), compare);

      int capacity = 4; // Initial capacity for the result array
      int **result = (int **)malloc(capacity * sizeof(int *));
      *returnSize = 0;

      for (int i = 0; i < numsSize - 2; i++) {
          if (i > 0 && nums[i] == nums[i - 1]) {
              continue; // Skip duplicate elements
          }

          int left = i + 1;
          int right = numsSize - 1;

          while (left < right) {
              int sum = nums[i] + nums[left] + nums[right];

              if (sum < 0) {
                  left++;
              } else if (sum > 0) {
                  right--;
              } else {
                  // Found a triplet with sum zero
                  result[*returnSize] = (int *)malloc(3 * sizeof(int));
                  result[*returnSize][0] = nums[i];
                  result[*returnSize][1] = nums[left];
                  result[*returnSize][2] = nums[right];
                  (*returnSize)++;

                  // Skip duplicate elements
                  while (left < right && nums[left] == nums[left + 1]) {
                      left++;
                  }
                  while (left < right && nums[right] == nums[right - 1]) {
                      right--;
                  }

                  left++;
                  right--;

                  // Resize the result array if needed
                  if (*returnSize == capacity) {
                      capacity *= 2;
                      result = (int **)realloc(result, capacity * sizeof(int *));
                  }
              }
          }
      }

      // Set returnColumnSizes to store the size of each row in the result array
      *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
      for (int i = 0; i < *returnSize; i++) {
          (*returnColumnSizes)[i] = 3;
      }

      return result;
  }

