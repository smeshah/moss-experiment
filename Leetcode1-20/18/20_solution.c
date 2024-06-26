
  int cmp(int *a, int *b)
  {
          return *a - *b;
  }

  void find(int *nums, int numsSize, int ***ret, int *rs, int target, int first)
  {
          int i, l, r;
          long sum;

          for (i = 0; i < numsSize - 2; i++) {
                  if (i > 0 && nums[i] == nums[i - 1])
                          continue;
                  else if ((long)nums[i] + nums[i + 1] + nums[i + 2] > target)
                          return;
                  else if ((long)nums[i] + nums[numsSize - 2] + nums[numsSize - 1] < target)
                          continue;

                  l = i + 1;
                  r = numsSize - 1;
                  while (l < r) {
                          if (l > i + 1 && nums[l] == nums[l - 1]) {
                                  l++;
                                  continue;
                          }

                          sum = (long)nums[l] + nums[i] + nums[r];
                          if (sum > target) {
                                          r--;
                          } else if (sum < target) {
                                          l++;
                          } else {
                                  int *new = (int *)malloc(sizeof(int) * 4);
                                  new[0] = first;
                                  new[1] = nums[i];
                                  new[2] = nums[l];
                                  new[3] = nums[r];
                                  (*ret)[(*rs)++] = new;

                                  l++;
                          }
                  }
          }
  }

  int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
  {
          *returnSize = 0;
          if (numsSize < 4)
                  return NULL;

          qsort(nums, numsSize, sizeof(int), cmp);

          int i, j;
          int rs;
          int **ret = (int **)malloc(sizeof(int *) * 2000);
          for (i = 0; i < numsSize - 3; i++) {
                  if (i > 0 && nums[i] == nums[i - 1])
                          continue;
                  else if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                          break;
                  else if ((long)nums[i] + nums[numsSize - 3] + nums[numsSize - 2] + nums[numsSize - 1] < target)
                          continue;
                  find(nums + i + 1, numsSize - i - 1, &ret, returnSize, target - nums[i], nums[i]);
          }

          if (!*returnSize)
                  return NULL;

          *returnColumnSizes = (int *)malloc(sizeof(int) * *returnSize);
          for (i = 0; i < *returnSize; i++) {
                  (*returnColumnSizes)[i] = 4;
          }

          return ret;
  }
