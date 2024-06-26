
  int min(int x, int y) {
      return x > y ? y : x;
  }

  int find_kth_element(int* nums1, int nums1_size, int* nums2, int nums2_size, int k) {
      if (nums1_size >  nums2_size)
          return find_kth_element(nums2, nums2_size, nums1, nums1_size, k);
      if (nums1_size == 0)
          return nums2[k-1];
      if (k == 1)
          return min(nums1[0], nums2[0]);
      int nums1_index = min(nums1_size, k / 2);
      int nums2_index = k - nums1_index;
      if (nums1[nums1_index-1] == nums2[nums2_index-1])
          return nums1[nums1_index-1];
      if (nums1[nums1_index-1] <  nums2[nums2_index-1])
          return find_kth_element(nums1 + nums1_index, nums1_size - nums1_index, nums2, nums2_index, k - nums1_index);
      return find_kth_element(nums1, nums1_index, nums2 + nums2_index, nums2_size - nums2_index, k - nums2_index);
  }

  double findMedianSortedArrays(int* nums1, int nums1_size, int* nums2, int nums2_size) {
      int sum = nums1_size + nums2_size;
      if (sum&1)
          return find_kth_element(nums1, nums1_size, nums2, nums2_size, sum / 2 + 1);
      return (find_kth_element(nums1, nums1_size, nums2, nums2_size, sum / 2 + 1) +
              find_kth_element(nums1, nums1_size, nums2, nums2_size, sum / 2)) / 2.0;
  }
