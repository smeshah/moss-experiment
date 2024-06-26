
  int cmp(const void *a, const void *b)
  {
      return *(int *)a - *(int *)b;
  }

  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
  {
      int count = 0;
      int *temp;
      int sum; 
      int **res = NULL;
  	// This is necessary
      if(nums == NULL || returnSize == NULL || returnColumnSizes == NULL) {
          return NULL;
      }

      qsort(nums, numsSize, sizeof(int), cmp);

      for (int i = 0; i < numsSize - 3; i++) {
          if (i > 0 && nums[i] == nums[i - 1]) {
              continue;
          }
  		// These came from other's solution. 
  		// This is good method to reduce time complexity
          if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
              break;
          }
          if (nums[i] + nums[numsSize - 3] + nums[numsSize - 2] + nums[numsSize - 1] < target) {
              continue;
          }

          for (int j = i + 1; j < numsSize - 2; j++) {
              if (j > i + 1 && nums[j] == nums[j - 1]) {
                  continue;
              }
  			// Same upon
              if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                  break;
              }
              if (nums[i] + nums[j] + nums[numsSize - 2] + nums[numsSize - 1] < target) {
                  continue;
              }

              int leftIndex = j + 1;
              int rightIndex = numsSize - 1;

              while (leftIndex < rightIndex) {
                  sum = nums[i] + nums[j] + nums[leftIndex] + nums[rightIndex];
                  if (sum == target) {
  					// Use **realloc** to get the best memory malloc
                      res = (int **)realloc(res, sizeof(int *)*(count+1));
                      res[count] = (int *)malloc(sizeof(int) * 4);
                      res[count][0] = nums[i];
                      res[count][1] = nums[j];
                      res[count][2] = nums[leftIndex];
                      res[count][3] = nums[rightIndex];
                      while (leftIndex < rightIndex && nums[leftIndex] == nums[leftIndex + 1]) {
                          leftIndex++;
                      }
                      while (leftIndex < rightIndex && nums[rightIndex] == nums[rightIndex - 1]) {
                          rightIndex--;
                      }
                      leftIndex++;
                      rightIndex--;
                      count++;
                  } else if (sum > target) {
                      rightIndex--;
                  } else {
                      leftIndex++;
                  }
              }
          }
      }
  	// This is a must
      *returnColumnSizes = (int *)malloc(sizeof(int) * count);
  	for (int i = 0; i < count; i++) {
  	   (*returnColumnSizes)[i] = 4;
  	}
      *returnSize = count;
      return res;
  }

