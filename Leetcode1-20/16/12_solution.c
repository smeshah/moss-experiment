
  int comp(int* a,int* b)
  {
      return(*a)-(*b);
  }

  int threeSumClosest(int* nums, int numsSize, int target) {
      if(numsSize==0 || numsSize<3)
      {
          return 0;
      }
      qsort(nums,numsSize,sizeof(int),comp);
      int closesum=INT_MIN;
      int mindiff=INT_MAX;
      for(int i=0;i<numsSize;i++)
      {
          int left=i+1;
          int right=numsSize-1;
          while(left<right)
          {
              int currentsum=nums[i]+nums[left]+nums[right];
              int currentdiff=abs(target-currentsum);
              if(currentdiff<mindiff)
              {
                  mindiff=currentdiff;
                  closesum=currentsum;
              }
              if(currentsum<target)
              {
                  left++;
              }
              else
              {
                  right--;
              }
          }
      }
      return closesum;
  }
