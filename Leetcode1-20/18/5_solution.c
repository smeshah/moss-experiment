
  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  int compare(const void *a, const void *b) {
      return (*(int *)a - *(int *)b);
  }

  int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
      if (nums == NULL || numsSize < 4){
          *returnSize = 0;
          return NULL;
      }
      qsort(nums, numsSize, sizeof(int), compare);
      int **result = (int **)malloc(sizeof(int *)* numsSize * numsSize);
      *returnColumnSizes = (int *)malloc(sizeof(int *)* numsSize * numsSize);
      *returnSize = 0;

      for (int first = 0; first < numsSize - 3; first++){
          if (first > 0 && nums[first] == nums[first - 1])
              continue;

          for (int second = first + 1; second < numsSize - 2; second++) {
              if (second > first + 1 && nums[second] == nums[second - 1])
                  continue;

              int third = second + 1;
              int fourth = numsSize - 1;

              while (third < fourth){
                  //Ã¥Â¦ÂÃ¦ÂÂÃ¤Â¸ÂÃ¤Â½Â¿Ã§ÂÂ¨double Ã¦ÂÂÃ¥ÂÂºÃ§ÂÂ¾signed integer overflow
                  double sum = ((double)nums[first] + nums[second] + nums[third] + nums[fourth]);
                  if (sum == target){
                      int* fournums = (int*)malloc(4 * sizeof(int));
                      fournums[0] = nums[first];
                      fournums[1] = nums[second];
                      fournums[2] = nums[third];
                      fournums[3] = nums[fourth];

                      result[*returnSize] = fournums;
                      (*returnColumnSizes)[*returnSize] = 4;
                      (*returnSize)++;

                      while (third < fourth && nums[third] == nums[third+1])
                          third++;
                      while (third < fourth && nums[fourth] == nums[fourth-1])
                          fourth--;
                      third++;
                      fourth--;
                  }else if (sum<target){
                      third++;
                  }else{
                      fourth--;
                  }
              }
          }
      }
      return result;
  }
