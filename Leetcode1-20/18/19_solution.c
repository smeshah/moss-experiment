
  int comparator(const void *a, const void *b){
      int l = *(const int*) a;
      int r = *(const int*) b;
      return l-r;
  }

  int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
      if(nums==NULL || numsSize == 0)
          return NULL;
      qsort((void *)nums, numsSize, sizeof(nums[0]), comparator);
      int **res = NULL;
      int count = 0;
      for(int i=0;i<numsSize;i++){
          if(i>0&&nums[i]==nums[i-1])
              continue;
          for(int j=i+1;j<numsSize;j++){
              if(j>i+1&&nums[j]==nums[j-1])
                  continue;
              int start = j+1, end = numsSize - 1;
              while(start < end){
                  int sum = nums[i]-target;
                  sum += nums[j] + nums[start] + nums[end];
                  if(sum == 0){
                      count++;
                      res = (int**)realloc(res, sizeof(int*) * count);
                      res[count-1] = (int*)malloc(sizeof(int) * 4);
                      res[count-1][0] = nums[i];
                      res[count-1][1] = nums[j];
                      res[count-1][2] = nums[start];
                      res[count-1][3] = nums[end];

                      while(start<end && nums[start]==nums[start+1])
                          start++;
                      while(start<end && nums[end]==nums[end-1])
                          end--;
                      start++;
                      end--;
                  } else if(sum>0)
                      end--;
                  else
                      start++;
              } 
          }
      }
      *returnSize = count;
      return res;
  }
