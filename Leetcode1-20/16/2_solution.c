
  int threeSumClosest(int* nums, int numsSize, int target){
  int i, j, k;
  int min_distance = abs(nums[0]+nums[1]+nums[2]-target);
  int min_sum = nums[0]+nums[1]+nums[2];
  for (i=0; i<numsSize-2; i++)
      for (j=i+1; j<numsSize-1; j++)
          for (k=j+1; k<numsSize; k++)
              if (abs(nums[i]+nums[j]+nums[k]-target)<min_distance) {
                  min_distance = abs(nums[i]+nums[j]+nums[k]-target);
                  min_sum = nums[i]+nums[j]+nums[k];
              }
  return min_sum;
  }
