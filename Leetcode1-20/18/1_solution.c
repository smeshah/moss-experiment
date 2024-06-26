
  int cmpfunc(const void* a, const void* b){
      return *(int*)a - *(int*)b;
  }
  int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
      int i, j, left, right;
      qsort(nums, numsSize, sizeof(int), cmpfunc);

      int** ans = (int**)malloc(1000000 * sizeof(int*));

      int idx = 0;
      for(i = 0;  i < numsSize -3; i++){
          if((i > 0) && nums[i] == nums[i-1])
              continue;
          for(j = i + 1; j < numsSize -2; j++){
              if(j > (i + 1) && nums[j] == nums[j-1])
                  continue;
                  left = j + 1;
                  right = numsSize - 1;
                  while(left < right){
                      long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                      if(sum == target){
                          ans[idx] = (int*)malloc(4 * sizeof(int));
                          ans[idx][0] = nums[i];
                          ans[idx][1] = nums[j];
                          ans[idx][2] = nums[left];
                          ans[idx][3] = nums[right];
                          idx++;
                          left++;  //Ã§ÂÂ¨Ã¥Â®ÂÃ¨Â¦Âshift
                          right--; //Ã§ÂÂ¨Ã¥Â®ÂÃ¨Â¦Âshift
                          while((left ) < right && nums[left] == nums[left - 1]) //Ã©ÂÂÃ¨Â¦ÂÃ¨Â¦Âshift
                              left++;

                          while((right) > left && nums[right] == nums[right + 1]) //Ã©ÂÂÃ¨Â¦ÂÃ¨Â¦Âshift
                              right--;

                      }
                      else if(sum > target){
                          right--;                      
                      }
                      else
                          left++;
                  }
          }
      }
      ans = (int**)realloc(ans, idx * sizeof(int*));
      * returnSize = idx;
      returnColumnSizes[0] = (int*)malloc(idx * sizeof(int));
      for(i = 0; i < idx; i++){
          returnColumnSizes[0][i] = 4;
      }
      return ans;
  }
