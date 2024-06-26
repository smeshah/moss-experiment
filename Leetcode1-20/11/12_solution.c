  #define min_h(a,b) ((a>b)?b:a)

  int maxArea(int* height, int heightSize) {
      int max = 0;
      for(int l=heightSize; l>0; l--)
      {
          int i,j;
          j = l-1;
          for(; j<heightSize; j++)
          {   
              i=j-l+1;
              if(max < min_h(height[i], height[j]) * (l-1))
                  max = min_h(height[i], height[j]) * (l-1);          
          }
      }
      return max;
  }
