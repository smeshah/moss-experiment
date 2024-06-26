


  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */
  int cmp_int(const void *a,const void *b)
  {
      return (*(int*)a-*(int*)b);
  }
  #define A (nums[i])
  #define B (*left)
  #define C (*right)
  #define MEM_ALLOC 100
  int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

      *returnColumnSizes = NULL;
      *returnSize = 0;
      qsort(nums,numsSize,sizeof(int),cmp_int);

      if(numsSize <3 ||nums[0]+nums[1]+nums[2]>0)
      {
          *returnColumnSizes = NULL;
          return NULL;
      }

      int *left,*right;
      int i;
      int **result = NULL;
      for(i=0;i<numsSize;i++)//-4 -1 -1 0 1 2 2
      {
          if(i>0 && nums[i-1] == nums[i])
              continue;

          left = nums+i+1;
          right = nums+numsSize-1;
          if(i>0 && nums[i-1]==nums[i])
              continue;
          while(left<right)//-1 -1 -1 0 0 0 1 2 2 2//-4 -1 -1 0 1 2
          {
              if(A+B+C>0)
                  right--;
              else if(A+B+C<0)
                  left++;
              else
              {
                  int *tuple = malloc(sizeof(int)*3);
                  tuple[0] = A;
                  tuple[1] = B;
                  tuple[2] = C;
                  if(*returnSize%MEM_ALLOC == 0)
                  {
                      result = (int**)realloc(result,sizeof(int*) * (*returnSize/MEM_ALLOC+1) *100 );
                      *returnColumnSizes = (int*)realloc(*returnColumnSizes,sizeof(int) * (*returnSize/MEM_ALLOC+1) * 100);
                  }
                  result[*returnSize] = tuple;
                  (*returnColumnSizes)[*returnSize] = 3;
                  (*returnSize)++;
                  while(left<right && right[0]==right[-1]) // ignore duplicated nums
                      right--;
                  right--; // move right pointer to next diff num
              }
          }
      }

      return result;
  }

