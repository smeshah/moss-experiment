


  int maxArea(int* height, int heightSize)
  {

      int i=0,j=0;
      int total=0, small;

      for(i=0; i<heightSize-1; i++)
      {

          for(j=i+1; j<heightSize; j++)
          {
              small = height[i]>height[j] ? height[j] : height[i];

              if((small*(j-i)) >= total)
                  total = small*(j-i);
          }

      }
      return total;
  }
