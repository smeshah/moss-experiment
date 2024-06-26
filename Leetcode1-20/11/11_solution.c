
  int maxArea(int* height, int heightSize){
      int start = 0, area, max = 0;
      int end = heightSize-1;
      while(start < end){
          area = min(height[start], height[end]) * (end - start);
          if(area > max){
              max = area;
          }
          if(height[start] < height[end]){
              start++;
          }
          else{
              end--;
          }
      }
      return max;
  }

  int min(int x, int y){
      if(x < y){
          return x;
      }
      else{
          return y;
      }
  }
