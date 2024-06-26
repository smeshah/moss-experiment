
  int maxArea(int* height, int heightSize)
  {
      int i = 0, j = heightSize - 1;
      int max_cap = INT_MIN;

      while (i < j) {
          int curr_cap = (j - i) * fmin(height[i], height[j]); // j-i -> length and fmin(height[i],height[j]) -> width  

          max_cap = fmax(max_cap, curr_cap); // update the max capcacity

          if (height[i] > height[j])
              j--;
          else
              i++;
      }

      return max_cap;
  }
