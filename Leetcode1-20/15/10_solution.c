
  int cmp(int *a, int *b)
  {
      return *a - *b;
  }

  int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
  {
      int **rst;
      int rstSize = 0;
      int basicSize = 8;
      int i, j, k, sum;

      rst = (int **)malloc(sizeof(int *) * basicSize);
      *returnColumnSizes = (int **)malloc(sizeof(int) * basicSize);

      qsort(nums, numsSize, sizeof(int), cmp);

      for (i = 0; i < numsSize - 1; i++) {
          if (i > 0 && nums[i] == nums[i - 1]) {
              continue;
          }

          j = i + 1;
          k = numsSize - 1;
          while (j < k) {
              sum = nums[i] + nums[j] + nums[k];
              if (sum == 0) {
                  rst[rstSize] = (int *)malloc(sizeof(int) * 3);
                  (*returnColumnSizes)[rstSize] = 3;
                  rst[rstSize][0] = nums[i];
                  rst[rstSize][1] = nums[j];
                  rst[rstSize][2] = nums[k];

                  rstSize++;

                  while (j < k && nums[j] == nums[j + 1]) {
                      j++;
                  }
                  j++;
                  k--;

                  if (rstSize == basicSize) {
                      basicSize *= 2;
                      rst = (int **)realloc(rst, sizeof(int *) * basicSize);
                      (*returnColumnSizes) = (int **)realloc((*returnColumnSizes),sizeof(int) * basicSize);
  				}

              } else if (sum > 0) {
                  k--;
              } else {
                  j++;
              }
          }
      }

      *returnSize = rstSize;

      return rst;
  }

