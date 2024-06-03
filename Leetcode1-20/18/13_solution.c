
  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */

  void selectionSort(int *arr, int size) {
      int min, minIdx, temp;
      for (int i = 0; i < size; i++) {
          min = arr[i];
          minIdx = i;
          for (int j = i + 1; j < size; j++) {
              if (arr[j] < min) {
                  min = arr[j];
                  minIdx = j;
              }
          }
          temp = min;
          arr[minIdx] = arr[i];
          arr[i] = temp;
      }
  }


  int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){

      int size = 10;
      int **ans = malloc(size * sizeof(int*));
      *returnColumnSizes = malloc(size * sizeof(int));

      *returnSize = 0;

      selectionSort(nums, numsSize);
      int minPtr, maxPtr, val;

      for (int i = 0; i < numsSize - 3; i++) {

          for (int j = i+1; j < numsSize - 2; j++) {
              minPtr = j + 1;
              maxPtr = numsSize - 1;

              if (i > 0 && (nums[i] == nums[i-1])) {
                  continue;
              }

              if (j > i+1 && (nums[j] == nums[j-1])) {
                  continue;
              }

              while (minPtr < maxPtr) {
                  val = nums[i] + nums[j];

                  if ((val >= 0 && INT_MAX - val < nums[minPtr]) ||
                      (val <  0 && INT_MIN - val > nums[minPtr])) {
                      minPtr++;
                      continue;
                  }
                  val += nums[minPtr];
                  if ((val >= 0 && INT_MAX - val < nums[maxPtr]) ||
                      (val <  0 && INT_MIN - val > nums[maxPtr])) {
                      minPtr++;
                      continue;
                  }
                  val += nums[maxPtr];


                  if (val < target) {
                      minPtr++;
                  }
                  else if (val > target) {
                      maxPtr--;
                  }
                  else {
                      *returnSize += 1;

                      if (*returnSize == size) {
                          size *= 2;
                          ans = realloc(ans, size * sizeof(int*));
                          *returnColumnSizes = realloc(*returnColumnSizes, size * sizeof(int));
                      }

                      ans[*returnSize - 1] = malloc(4 * sizeof(int));

                      ans[*returnSize - 1][0] = nums[i];
                      ans[*returnSize - 1][1] = nums[j];
                      ans[*returnSize - 1][2] = nums[minPtr];
                      ans[*returnSize - 1][3] = nums[maxPtr];

                      (*returnColumnSizes)[*returnSize - 1] = 4;

                      minPtr++;
                      while (minPtr < numsSize && nums[minPtr] == nums[minPtr - 1]) {
                          minPtr++;
                      }
                  }
              }
          }
      }

      return ans;
  }


