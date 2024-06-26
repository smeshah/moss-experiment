

  int comparator(const void *a, const void *b)
  {
      int l = *(const int*)a;
      int r = *(const int*)b;
      return l-r;
  }
  int** fourSum(int* arr, int size, int target, int* returnSize) {
      if(arr == NULL || size == 0)
          return NULL;

      qsort((void *)arr, size, sizeof(arr[0]),comparator );

      int count = 0;
      int **res = NULL;
      int sum;

      for(int i = 0; i < size; i++)
      {
          if(i > 0 && arr[i] == arr[i-1])
                  continue;
          for(int j = i + 1; j < size;j++)
          {
              if(j > i + 1 && arr[j] == arr[j-1])
              continue;

              int start = j + 1;
              int end = size -1;

              while(start < end)
              {
                  sum = arr[i] + arr[j] + arr[start] + arr[end];
                  if(sum == target)
                  {
                      count++;
                      res = (int **)realloc(res, sizeof(int *)*count);
                      res[count - 1] = (int *)malloc(sizeof(int)*4);
                      res[count - 1][0] = arr[i];
                      res[count - 1][1] = arr[j];
                      res[count - 1][2] = arr[start];
                      res[count - 1][3] = arr[end];

                      while(start < end && arr[start] == arr[start + 1])
                          start++;
                      while(start < end && arr[end] == arr[end - 1])
                          end--;

                      start++;
                      end--;
                  }
                  else if(sum > target)
                      end--;
                  else
                      start++;
              }
          }
      }

      *returnSize = count;
      return res;
  }

