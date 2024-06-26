

  /**
   * Return an array of arrays of size *returnSize.
   * Note: The returned array must be malloced, assume caller calls free().
   */

  int comparator(const void *a, const void *b)
  {
      int l = *(const int*)a;
      int r = *(const int*)b;
      return l-r;
  }
  int** threeSum(int* arr, int size, int* returnSize) 
  {
      if(arr == NULL || size == 0)
          return NULL;

      qsort((void *)arr, size, sizeof(arr[0]),comparator );
      int count = 0;
      int **res = NULL;

      for(int i = 0; i < size; i++)
      {

          int start = i + 1;
          int end = size - 1;
          int sum;

  	// handles duplicates for i position
          if(i > 0 && arr[i] == arr[i - 1])
              continue;

          while(start < end )
          {

              sum = arr[i] + arr[start] + arr[end];
              if(sum == 0)
              {
                  count++;
                  res = (int **)realloc(res, sizeof(int *) * count);
                  res[count - 1] = (int *) malloc(sizeof(int)*3);
                  res[count - 1][0] = arr[i];
                  res[count - 1][1] = arr[start];
                  res[count - 1][2] = arr[end];
                  //handle duplicates for start index
                  while(start < end && arr[start] == arr[start + 1])
                      start++;
                  //handle duplicates for end index
                  while(start < end && arr[end] == arr[end -1])
                      end--;

                  start++;
                  end--;
              }
              else if(sum > 0)
                  end--;
              else
                  start++;
          }
      }
      *returnSize = count;
      return res;
  }


