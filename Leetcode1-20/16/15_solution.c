

  int cmp(int *a, int *b)
  {
          return *a - *b;
  }

  long _abs(long a)
  {
          return a > 0 ? a : 0 - a;
  }

  bool check_closet(long target, long new, long old)
  {
          if (_abs(target - new) < _abs(target - old))
                  return true;
          return false;
  }

  int find_closet(int *nums, int numsSize, int target)
  {
          int i, l, r;
          int sum;
          int closet = 0x7fffffff;

          for (i = 0; i < numsSize; i++) {
                  if (i > 0 && nums[i] == nums[i - 1])
                          continue;

                  l = i + 1;
                  r = numsSize - 1;
                  while (l < r) {
                          if (l > i + 1 && nums[l] == nums[l - 1]) {
                                  l++;
                                  continue;
                          }

                          sum = nums[l] + nums[i] + nums[r];
                          if (check_closet(target, sum, closet)) {
                                  if (sum == target)
                                          return sum;
                                  closet = sum;
                          }

                          if (sum > target) {
                                  r--;
                          } else {
                                  l++;
                          }
                  }
          }

          return closet;
  }

  int threeSumClosest(int* nums, int numsSize, int target)
  {
          qsort(nums, numsSize, sizeof(int), cmp);
          return find_closet(nums, numsSize, target);
  }
