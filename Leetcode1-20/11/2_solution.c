
  int maxArea(int* height, int heightSize) {
      int start = 0, end = heightSize - 1, max = 0;
      while(start < end) {
          int area = (end - start) * (height[start] < height[end] ? height[start++] : height[end--]);
          max = (area > max) ? area : max;
      }
      return max;
  }
