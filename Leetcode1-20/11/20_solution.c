
  //https://leetcode.com/problems/container-with-most-water/
  //08-11-2023
  //Container With Most Water

  #include <stdio.h>



  int greaterIndex(int n, int* arr, int len, int start){//finding the last num that bigger than n
      for(int i = len-1; i > start; i--){
          if(arr[i] >= n){
              return i;
          }
      }
      return -1;
  }

  static inline maxNum(int a,int b){
      if(a > b){
          return a;
      }
      return b;
  }

  static inline minNum(int a, int b){
      if (b > a){
          return a;
      }
      return b;

  }
  int maxArea(int* height, int heightSize) {
      int maxArea = 0;
      int maxIndex;

      for(int i = 0; i < (heightSize-1); i++){
          maxIndex = greaterIndex(height[i], height, heightSize, i);
          if(maxIndex == -1){
              for(int u = i; u < heightSize; u++){
                  maxArea = maxNum(maxArea, minNum(height[i], height[u])*(u-i));
              }
          }

          else{
              maxArea = maxNum((maxIndex-i)*height[i], maxArea);
              for(int z = maxIndex+1; z < heightSize; z++){
                  maxArea = maxNum(maxArea, minNum(height[i], height[z])*(z-i));
              }

          }


      }

      return maxArea;

  }
