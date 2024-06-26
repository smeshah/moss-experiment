
  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */

  typedef struct{

  int sum_Size;
  int o_row;
  int target;

  int i;
  int j;
  int** output;

  }stSumdata;

  int check(int*nums,stSumdata *smDt)
  {
      long int t = 0;
      t = smDt->target - ((long )nums[smDt->i] + nums[smDt->j]);

      if(t >= 0 && nums[smDt->sum_Size - 1] >= 0) return 1;
      else if(t < 0 && nums[smDt->j + 1] < 0 ) return 1;

      return -1;
  }

  int find(int* nums, int start, int l, long int target)
  {

      int mid =0;
      int left = start;
      int right = l;

      while(left<=right)
      {
          mid = (left+right)/2;
          if(nums[mid] == target) return mid;
          else if(target < nums[mid]) right = mid - 1;
          else left = mid + 1;
      }
      return -1;
  }

  int cmpfunc (const void * a, const void * b)
  {
      return ( *(int*)a - *(int*)b );
  }


  void twoSum(int*nums,stSumdata *smDt)
  {
      int rec = -1;
      int k = smDt->j+ 1;
      long int t = 0;

      for(; k < smDt->sum_Size; k++)
      {
          t  = smDt->target - ((long )nums[smDt->i] + nums[smDt->j] + nums[k]);
          rec = find(nums,k+1,smDt->sum_Size-1,t);

          if(rec >= 0)
          {
              int score = 0;
              if(smDt->o_row > 0)
              {
                  if(smDt->output[smDt->o_row-1][0] ==  nums[smDt->i]) score++;
                  if(smDt->output[smDt->o_row-1][1] ==  nums[smDt->j]) score++;
                  if(smDt->output[smDt->o_row-1][2] ==  nums[k]) score++;
                  if(smDt->output[smDt->o_row-1][3] ==  nums[rec]) score++;
              }
              if(score >= 4) continue;

              smDt->output[smDt->o_row][0] = nums[smDt->i];
              smDt->output[smDt->o_row][1] = nums[smDt->j];
              smDt->output[smDt->o_row][2] = nums[k];
              smDt->output[smDt->o_row][3] = nums[rec];
              smDt->o_row++;
          }
      }
  }

  void threeSum(int*nums,stSumdata *smDt)
  {
      int k = smDt->i + 1;
      for(;k < smDt->sum_Size -2; k++)
      {      
          smDt->j = k;

          if(check(nums,smDt)>0) twoSum(nums,smDt);
          while( k < smDt->sum_Size-2)
          {
              if(nums[k] != nums[k+1]) break;
              k++;
          }
      }
  }


  int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){

      stSumdata smDt =
      {
          .sum_Size = numsSize,
          .o_row = 0,
          .target = target,
      };

      smDt.output = (int**) calloc(100,sizeof(int*));
      for(uint8_t i = 0; i < 100; i++)
      {
          (smDt.output)[i] = (int *) calloc(4, sizeof(int));
      }

      int o_row = 0;

      qsort(nums,numsSize,4,cmpfunc);

      for(int i = 0; i < numsSize-3; i++)
      {
          smDt.i = i;
          threeSum(nums,&smDt);
          while( i < numsSize-3)
          {
              if(nums[i] != nums[i+1]) break;
              i++;
          }
      }

      *returnSize =  smDt.o_row;
      returnColumnSizes[0] = (int*) malloc(sizeof(int) * smDt.o_row);
      for(uint8_t i = 0; i < smDt.o_row; i++)
      {
          returnColumnSizes[0][i] = 4;
      }

      return smDt.output;
  }
