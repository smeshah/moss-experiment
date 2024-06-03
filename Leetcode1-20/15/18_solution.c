  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
      int *p, *q, index;
      int **triplets, tIndex = 0;
      int Sum;

      qsort(nums, numsSize, sizeof(int), cmpfunc);
      index = 0;

      *returnColumnSizes = (int *) malloc ((numsSize * numsSize) * sizeof(int));
      triplets = (int **) malloc ((numsSize * numsSize) * sizeof(int *));

      while (index < numsSize - 2)
      {
          p = &nums[index + 1];
          q = &nums[numsSize - 1];

          while (p < q)
          {
              if (index != 0 && nums[index] == nums[index-1])
              {
                  break;
              }
              Sum = *p + *q + nums[index];

              if (Sum > 0)
              {
                  q--;
              }
              else if (Sum < 0)
              {
                  p++;
              }
              else
              {
                  triplets[tIndex] = (int *) malloc (3 * sizeof(int));
                  (*returnColumnSizes)[tIndex] = 3;

                  triplets[tIndex][0] = *p;
                  triplets[tIndex][1] = *q;
                  triplets[tIndex][2] = nums[index];
                  tIndex++;
                  p++;
                  while (p < q && *p == *(p-1))
                      p++;
              }
          }

          index++;
      }
      *returnSize = tIndex;
      return triplets;
  }

