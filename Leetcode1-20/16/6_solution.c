  int cmp(const void *a, const void *b)
  {
      return *(int *)a - *(int *)b;
  }

  int threeSumClosest(int* nums, int numsSize, int target) {
      qsort(nums, numsSize, sizeof(int), cmp);

      int minDiff = INT_MAX;
      int sum;
      for(int i=0; i<numsSize-2; i++)
      {
          int l, r, delta, twoSum;
          l = i+1;
          r = numsSize-1;
          // a+b+c|d -> a+b|d-c; delta is d-c; twoSum is a+b 
          delta = target - nums[i];

          while(l < r)
          {
              twoSum = nums[l] + nums[r];
              int diff = twoSum - delta;
              if(abs(diff) <= minDiff)
              {
                  minDiff = abs(diff);
                  sum = twoSum + nums[i];
              }

              if(!diff)
                  return target;
              else if(diff < 0)
                  l++;
              else
                  r--;
          }

      }
      return sum;

  }
