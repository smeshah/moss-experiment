
  int compare(const void *a1, const void *b1) {
      const int a = *(int *)a1;
      const int b = *(int *)b1;
      if (a < b)
          return -1;
      else if (a == b)
          return 0;
      else
          return 1;
  }

  int binarySearch(int arr[], int l, int r, int x, int set)
  {
      if (r >= l) {
          int mid = l + (r - l) / 2;

          if (arr[mid] == x)
              return mid;

          if (arr[mid] > x)
              return binarySearch(arr, l, mid - 1, x, set);

          return binarySearch(arr, mid + 1, r, x, set);
      }

      return set;
  }

  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
      int N = 0;
      int allocated = numsSize * 2;
      int **res = (int **)malloc(allocated * sizeof(int *));
      *returnSize = 0;
      if (numsSize < 3)
          return res;

      qsort(nums, numsSize, sizeof(*nums), compare);
      int k = numsSize;
      for (int i = 0; i < numsSize && nums[i] <= 0; ++i) {
          for (int j = i + 1; j < numsSize; ++j) {
              int search = -(nums[i] + nums[j]);
              if (search < 0)
                  break;

              k = binarySearch(nums, j + 1, numsSize - 1, search, numsSize);
              if (k < numsSize) {
                  res[N] = malloc(sizeof(int) * 3);
                  res[N][0] = nums[i];
                  res[N][1] = nums[j];
                  res[N][2] = nums[k];
                  ++N;

                  if (j == i + 1)
                      numsSize = k;

                  if (N == allocated) {
                      allocated *= 2;
                      res = (int **)realloc(res, allocated * sizeof(int *));
                  }
              } 

              while (j + 1 < numsSize && nums[j] == nums[j + 1])
                  ++j;
          }

          while (i + 1 < numsSize && nums[i] == nums[i + 1])
              ++i;
      }

      *returnSize = N;
      *returnColumnSizes = malloc(N * sizeof(int));    
      for (int i = 0; i < N; ++i)
          (*returnColumnSizes)[i] = 3;

      return res;
  }
