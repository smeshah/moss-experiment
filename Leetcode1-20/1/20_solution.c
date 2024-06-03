
  /**
   * Note: The returned array must be malloced, assume caller calls free().
   */
  int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
      int* result = (int*)malloc(2 * sizeof(int));
      int one = 0, two = 0;
      for (int i = 0; i < numsSize; i++) {
          for (int j = i + 1; j < numsSize; j++) {
              if (nums[i] + nums[j] == target) {
                  one = i;
                  two = j;
                  break; 
              }
          }
      }
      result[0] = one;
      result[1] = two;
      *returnSize = 2;
      return result;
  }

