
  int min(int a, int b)
  {
      return a<=b ? a : b;
  }

  int maxArea(int* height, int heightSize){
      // Only 1 column cannot surround any water. 
      if(heightSize <= 1)
          return 0;

      // 2 columns can only have one possible solution.
      if(heightSize == 2)
      {
          return min(height[0], height[1]);
      }

      int front = 0;
      int back = heightSize-1;
      int max_area = 0;

      // Working inward from the front and the back.
      while(front < back)
      {
          int current_area = (back - front) * min(height[back], height[front]);

          if(current_area > max_area)
              max_area = current_area;

          // Whichever height is smaller is the one restricting our max.
          // So, we look for a taller column to replace our smallest one.
          if(height[back] < height[front])
          {
              back--;
          } 
          else
          {
              front++;
          }
      }

      return max_area;
  }
