
  int** threeSum(int* nums, int numsSize, int* returnSize);
  int cmpInt(const void * a, const void * b);
  int* addSolution(int a, int b, int c);

  int** threeSum(int* nums, int numsSize, int* returnSize)
  {
      int i, j, k;
      int nc = 0, zc = 0, pc = 0;

      int** r = malloc(sizeof(int*) * numsSize * (numsSize-1) *(numsSize-2) / 6);
      *returnSize = 0;

      if (numsSize < 3)
          return r;

      qsort(nums, numsSize, sizeof(int), cmpInt);

      for (i = 0; i < numsSize; i++) {
          if (nums[i] < 0) nc++;
          else if (nums[i] == 0) zc++;
          else pc++;
      }

      // 3 zeros
      if (zc >= 3)
          r[(*returnSize)++] = addSolution(0, 0, 0);

      // 1 zero
      if (zc >= 1) {
          for (i = 0, j = numsSize-1; i < nc && j > nc + zc - 1;) {
              if (nums[i] + nums[j] < 0) i++;
              else if (nums[i] + nums[j] > 0) j--;
              else if (i > 0 && nums[i] == nums[i-1]) i++; // Skip repeated number
              else if (j < numsSize-1 && nums[j] == nums[j+1]) j--; // Skip repeated number
              else r[(*returnSize)++] = addSolution(nums[i++], 0, nums[j--]);
          }
      }

      // 0 zero, 2 negatives
      if (nc >= 2 && pc >= 1) {
          for (i = 0; i < nc; i++) {
              if (nums[i] + nums[numsSize-1] < 0);
              else if (i > 0 && nums[i] == nums[i-1]);
              else
                  for (j = i+1, k = numsSize-1; j < nc && k > nc + zc - 1;) {
                      if (nums[i] + nums[j] + nums[k] < 0) j++;
                      else if (nums[i] + nums[j] + nums[k] > 0) k--;
                      else if (j > i+1 && nums[j] == nums[j-1]) j++; // Skip repeated number
                      else if (k < numsSize-1 && nums[k] == nums[k+1]) k--; // Skip repeated number
                      else r[(*returnSize)++] = addSolution(nums[i], nums[j++], nums[k--]);
                  }
          }
      }

      // 0 zero, 2 positives
      if (nc >= 1 && pc >= 2) {
          for (i = numsSize-1; i > nc + zc - 1; i--) {
              if (nums[i] + nums[0] > 0);
              else if (i < numsSize-1 && nums[i] == nums[i+1]);
              else
                  for (j = i-1, k = 0; j > nc + zc - 1 && k < nc;) {
                      if (nums[i] + nums[j] + nums[k] > 0) j--;
                      else if (nums[i] + nums[j] + nums[k] < 0) k++;
                      else if (j < i-1 && nums[j] == nums[j+1]) j--; // Skip repeated number
                      else if (k > 0 && nums[k] == nums[k-1]) k++; // Skip repeated number
                      else r[(*returnSize)++] = addSolution(nums[i], nums[j--], nums[k++]);
                  }
          }
      }

      return r;
  }

  int cmpInt(const void * a, const void * b)
  {
      return (*(int*)a - *(int*)b);
  }

  int* addSolution(int a, int b, int c)
  {
      int* sol = malloc(sizeof(int) * 3);
      sol[0] = a;
      sol[1] = b;
      sol[2] = c;
      return sol;
  }
