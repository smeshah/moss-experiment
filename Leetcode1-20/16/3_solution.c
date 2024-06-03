
  int compare(const void *a, const void *b) {
      return (*(int *)a - *(int *)b);
  }

  int threeSumClosest(int *nums, int numsSize, int target) {
      qsort(nums, numsSize, sizeof(int), compare);

      int closestSum = nums[0] + nums[1] + nums[2];
      int minDiff = abs(target - closestSum);

      for (int i = 0; i < numsSize - 2; i++) {
          int left = i + 1;
          int right = numsSize - 1;

          while (left < right) {
              int sum = nums[i] + nums[left] + nums[right];
              int diff = abs(target - sum);

              if (diff < minDiff) {
                  minDiff = diff;
                  closestSum = sum;
              }

              if (sum < target) {
                  left++;
              } else {
                  right--;
              }
          }
      }

      return closestSum;
  }

