
  int maxArea(int *height, int heightSize)
  {
      int right = heightSize - 1;
      int left = 0;
      int ris = 0;
      while (left != right&&right<heightSize&&left<heightSize)
      {

          if (height[left] < height[right])
          {
              int curr = (right - left) * height[left];
              if (ris < curr)
              {
                  ris = curr;
              }
              left++;
          }
          else
          {
              int curr=(right - left)*height[right];
              if (ris < curr)
              {
                  ris=curr;
              }
              right--;
          }
      }
      return ris;
  }
