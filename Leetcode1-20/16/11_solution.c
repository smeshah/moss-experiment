

  int cmp(const void *a, const void *b)
  {
      return *(int *)a - *(int *)b;
  }

  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  int threeSumClosest(int* nums, int numsSize, int target){
      int sum, result; 
      int min = 99999;

      qsort(nums, numsSize, sizeof(int), cmp);

      for (int i = 0; i < numsSize - 2; i++) {
          int leftIndex = i + 1;
          int rightIndex = numsSize - 1;

          while (leftIndex < rightIndex) {
              sum = nums[i] + nums[leftIndex] + nums[rightIndex];
              if (sum == target) {
                  return target;
              } else if (sum > target) {
                  if (abs(sum - target) < min) {
                      result = sum;
                      min = abs(sum - target);
                  }
                  do {
                      rightIndex--;
                  } while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex + 1]);

              } else {
                  if (abs(target - sum) < min) {
                      result = sum;
                      min = abs(target - sum);
                  }
                  do {
                      leftIndex++;
                  } while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex - 1]);
              }
          }
      }

      return result;
  }
