
  #define MAX_RESULT 50

  int cmpfn(void * a, void * b)
  {
      return *(int*)a - *(int*)b;
  }

  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
      *returnSize = 0;
      if (numsSize < 4)
          return NULL;

      qsort(nums, numsSize, sizeof(int), cmpfn);

      int a, b, c, d;


      int ** res = malloc(sizeof(int*) * MAX_RESULT);
      *returnColumnSizes = malloc(sizeof(int) * MAX_RESULT);

      for (a = 0; a < numsSize - 3; a++)
      {
          if (a > 0 && nums[a] == nums[a-1])
              continue;
          for (b = a + 1; b < numsSize - 2; b++)
          {
              if (b != a + 1 && nums[b] == nums[b-1])
                  continue;

              long tgt = (long)target - (long)nums[a] - (long)nums[b];
              for (c = b + 1, d = numsSize - 1; c < d;)
              {
                  if (c != b + 1 && nums[c] == nums[c-1])
                  {
                      c++;
                      continue;
                  }

                  long diff = (long)tgt - (long)nums[d];
                  if (nums[c] == diff)
                  {
                      // add to resultset
                      res[*returnSize] = malloc(sizeof(int) * 4);
                      res[*returnSize][0] = nums[a]; 
                      res[*returnSize][1] = nums[b]; 
                      res[*returnSize][2] = nums[c]; 
                      res[*returnSize][3] = nums[d]; 
                      (*returnColumnSizes)[*returnSize] = 4;
                      (*returnSize)++;
                      c++;
                  }
                  else if (nums[c] < diff)
                      c++;
                  else
                      d--;
              }
          }
      }
      return res;
  }
