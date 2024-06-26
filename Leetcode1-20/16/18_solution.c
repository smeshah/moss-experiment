
  int comparator(const void *a, const void *b){
      int l = *(const int *)a;
      int r = *(const int *)b;
      return l-r;
  }

  int threeSumClosest(int* nums, int numsSize, int target) {
      qsort((void *)nums, numsSize, sizeof(nums[0]), comparator);
      int res = 0, flag = 0;;
      for(int i=0;i<numsSize;i++){
          int start = i+1;
          int end = numsSize-1;
          int sum = 0;
          while(start<end){
              sum = nums[i]+nums[start]+nums[end];
              if(flag==1)
                  res = (abs(sum-target))<(abs(res-target))?sum:res;
              else
                  res = sum;

              flag=1;

              if((sum-target)<0)
                  start++;
              else if((sum-target)>0)
                  end--;
              else
                  return res;
          }
      }
      return res;
  }
