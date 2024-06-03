
  int max(int a, int b){
      return a > b ? a : b;
  }

  int min(int a, int b) {
      return a < b ? a : b;
  }

  int maxArea(int* height, int heightSize) {
      int max_area = 0;
      // int max_h = 0;
      int area = 0;
      int left = 0;
      int right = heightSize-1;

      while(left < right){
          area = (right-left) * min(height[left], height[right]);
          max_area = max(area, max_area);

          if(height[left] < height[right]) left++;
          else right--;
      }
      return max_area;
  }

      // for(int i=0; i<heightSize; i++){
      //     for(int j=i; j<heightSize; j++){
      //         min_h = height[i];
      //         if(height[j]<min_h)  min_h = height[j];
      //         area = (j-i)*min_h;
      //         if(max_area<area) max_area = area;
      //     }
      // }
      // return max_area;
