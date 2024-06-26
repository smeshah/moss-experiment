
  int maxArea(int* height, int heightSize){
      int l=0, r=heightSize-1;
      int max = 0;
      while(l < r)
      {
          int area = (r-l)*(height[l] < height[r]? height[l++] : height[r--]);
          max = max > area? max : area;
      }
      return max;
  }
