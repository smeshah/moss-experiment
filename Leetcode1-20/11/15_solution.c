
  int maxArea(int* height, int heightSize) {
      int ret=0;
      for(int i=0;i<heightSize-1;i++){
          for(int j=i+1;j<heightSize;j++){
              int temp=(height[i]<height[j]?height[i]:height[j])*(j-i);
              ret=ret>temp?ret:temp;
          }
      }
      return ret;
  }
