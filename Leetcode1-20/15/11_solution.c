
  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
      for(int i=0;i<numsSize-1;i++) {
          for(int j=i+1;j<numsSize;j++) {
              if(nums[j]<nums[i]) {
                  int t = nums[j];
                  nums[j] = nums[i];
                  nums[i] = t;
              }
          }
      }
      int** result = (int**)malloc(sizeof(int*) * numsSize * numsSize);
      *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
      int resultSize = 0;
      for(int i=0;i<numsSize-2;i++) {
          if(i>0 && nums[i]==nums[i-1]) {
              continue;
          }
          int l=i+1, r=numsSize-1;
          while(l<r) {
              int s = nums[i] + nums[l] + nums[r];
              if(s<0) {
                  l++;
              } else if(s>0) {
                  r--;
              } else {
                  int* triplet = (int*)malloc(sizeof(int) * 3);
                  triplet[0] = nums[i];
                  triplet[1] = nums[l];
                  triplet[2] = nums[r];
                  result[resultSize] = triplet;
                  (*returnColumnSizes)[resultSize] = 3;
                  resultSize++;
                  while(l<r && nums[l]==nums[l+1]) {
                      l++;
                  }
                  while(l<r && nums[r]==nums[r-1]) {
                      r--;
                  }
                  l++;
                  r--;
              }
          }
      }

      *returnSize = resultSize;
      return result;
  }

