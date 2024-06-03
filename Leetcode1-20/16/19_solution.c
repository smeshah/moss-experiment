
  #include <stdlib.h> // Include this for the abs function
  #include <limits.h>
  int threeSumClosest(int nums[], int numsSize, int target) {
      int closestSum, minDiff = INT_MAX; // Initialize minDiff to a large value

      for (int i = 0; i < numsSize - 2; i++) {
          for (int j = i + 1; j < numsSize - 1; j++) {
              for (int k = j + 1; k < numsSize; k++) {
                  int currentSum = nums[i] + nums[j] + nums[k];
                  int diff = abs(target - currentSum);

                  if (diff < minDiff) {
                      minDiff = diff;
                      closestSum = currentSum;
                  }
              }
          }
      }

      return closestSum;
  }

