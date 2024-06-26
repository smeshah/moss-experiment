
  double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
          int n1 = 0, n2 = 0, i;
          int *om, *m;
          int t = nums1Size + nums2Size;
          double ret;
          om = m = malloc((nums1Size + nums2Size) * sizeof(int));

          /* Merge the sorted arrays like mergesort */
          while (t--) {
              if ((n1 != nums1Size) && (n2 != nums2Size)) {
                  if (*nums1 < *nums2) {
                          *m++ = *nums1++;
                          n1++;
                  } else {
                          *m++ = *nums2++;
                          n2++;
                  }
              }
          }
          if (n2 != nums2Size) {
                  int left = nums2Size - n2;
                  while(left--) {
                          *m++ = *nums2++;
                  }
          }
          if (n1 != nums1Size) {
                  int left = nums1Size - n1;
                  while(left--) {
                          *m++ = *nums1++;
                  }
          }
          t = nums1Size + nums2Size;
          if (t&1) { /* odd */
                  ret = (double)om[t/2];
          } else {
                  ret = ((double)(om[t/2] + om[t/2 - 1])/2);
          }
  		free(om);
          return ret;
  }
