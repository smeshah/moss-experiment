
  void swap(int *a, int *b)
  {
      int temp = *a;
      *a = *b;
      *b = temp;
  }

  int partition(int arr[], int low, int high)
  {
      int pivot = arr[high];
      int i = (low - 1);

      for (int j = low; j <= high - 1; j++)
      {
          if (arr[j] < pivot)
          {
              i++;
              swap(&arr[i], &arr[j]);
          }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
  }

  void quickSort(int arr[], int low, int high)
  {
      if (low < high)
      {
          int pi = partition(arr, low, high);
          quickSort(arr, low, pi - 1);
          quickSort(arr, pi + 1, high);
      }
  }
  void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
      int i = 0, j = 0, k = 0;

      while (i < size1 && j < size2) {
          if (arr1[i] <= arr2[j]) {
              merged[k++] = arr1[i++];
          } else {
              merged[k++] = arr2[j++];
          }
      }

      while (i < size1) {
          merged[k++] = arr1[i++];
      }
      while (j < size2) {
          merged[k++] = arr2[j++];
      }
  }
  double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
  {
      int total_len = nums1Size + nums2Size;
      int *nums3=malloc(total_len*sizeof(int));
      mergeArrays(nums1,nums1Size,nums2,nums2Size,nums3);
      quickSort(nums3,0,total_len-1);
      if (total_len % 2 == 0)
      {
          int mid=total_len/2;
          int sum=(nums3[mid]+nums3[mid-1]);
          double ris=(double)sum / 2.0;
          return ris;
      }
      else
      {
          int mid=total_len/2;
          return nums3[mid];
      }

  }
