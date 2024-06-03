
  int cmp(const void* a,const void* b)
  {
      return (*(int*)a-*(int*)b);
  }
  int absl(int a,int b)
  {
      if(a-b>=0)
      return a-b;
      return b-a;
  }
  int threeSumClosest(int* nums, int numsSize, int target){
  qsort(nums,numsSize,sizeof(int),cmp);
  int min_sum,min_diff=INT_MAX,k,j;
  for(int i=0;i<numsSize-2;i++)
  {
      j=i+1;
      k=numsSize-1;
      while(j<k)
      {
         if(min_diff>absl(target,nums[i]+nums[j]+nums[k]))
        {
            min_diff=absl(target,nums[i]+nums[j]+nums[k]);
            min_sum=nums[i]+nums[j]+nums[k];
        }
        if(nums[i]+nums[j]+nums[k]>target)
        k--;
        else
        {
            if(nums[i]+nums[j]+nums[k]<target)
            j++;
            else
            return nums[i]+nums[j]+nums[k];
        }
      }
  }
  return min_sum;
  }
