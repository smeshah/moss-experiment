  #define SUM(a,b,c) ((a)+(b)+(c))

  int threeSumClosest(int* nums, int numsSize, int target) {
      if(numsSize == 3)
          return SUM(nums[0],nums[1],nums[2]);

      int min_delta = SUM(nums[0],nums[1],nums[2]) - target;
      for(int i=0; i<numsSize; i++)
          for(int j=i+1; j<numsSize; j++)
              for(int k=j+1; k<numsSize; k++)
              {
                  int delta = SUM(nums[i],nums[j],nums[k]) - target;
                  if(!delta)
                      return target;
                  else if(abs(delta) <= abs(min_delta))
                      min_delta = delta;
              }
      return (min_delta + target);
  }
