
  void Bubble_Sort(int* nums,int numsSize) {
      int p,i;
      int temp;
      int flag;

      for (p=numsSize-1;p>=0;p--) {
          flag=0;
          for (i=0;i<p;i++) {
              if (nums[i]>nums[i+1]) {
                  temp=nums[i];
                  nums[i]=nums[i+1];
                  nums[i+1]=temp;
                  flag=1;
              } 
          }
          if (flag==0) break;
      }  
  }

  int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
      if (!nums || numsSize<4) return 0;

      int total=100;
      int** res=(int**)malloc(sizeof(int*)*total);
      for (int n;n<total;n++) {
          res[n]=(int*)malloc(sizeof(int)*4);
      }

      Bubble_Sort(nums,numsSize);

      int size=0;
      int sum;
      int i,j,m,n;

      for (i=0;i<numsSize-3;i++)  {
          if (i>0&&nums[i]==nums[i-1]) continue;

          for (j=i+1;j<numsSize-2;j++) {
              if (j>i+1&&nums[j]==nums[j-1]) continue;

              m=j+1;
              n=numsSize-1;

              while (m<n) {
                  sum=nums[i]+nums[j]+nums[m]+nums[n];
                  if (sum==target) {
                      if (size>0&&res[size-1][0]==nums[i]&&res[size-1][1]==nums[j]&&res[size-1][2]==nums[m]&&res[size-1][3]==nums[n]) {
                          m++;
                          n--;
                          continue;
                      }

                      if (size==total) {
                          res=(int**)realloc(res,sizeof(int*)*total);
                          for (int t=size;t<total;t++) {
                              res[t]=(int*)malloc(sizeof(int)*4);
                          }
                      }

                      res[size][0]=nums[i];
                      res[size][1]=nums[j];
                      res[size][2]=nums[m];
                      res[size][3]=nums[n];

                      size++;
                      m++;
                      n--; 
                  }
                  else if (sum<target) {
                      m++;
                  }
                  else {
                      n--;
                  }
              }
          }
      }

      *returnSize=size;
      return res;
  }
