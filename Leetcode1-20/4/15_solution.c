
  double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
      int total = nums1Size+nums2Size;
      int index=-1, index1=-1;
      int median=0, flag=0; 
      int i1, i2, counter=0;
      if(total%2==0)
      {
          index = (total/2) -1;
          index1 = index+1;
      }
      else
      {
          index = total/2;
          flag=1;            //when total is odd
      }
      for(i1=0, i2=0 ; i1<nums1Size&&i2<nums2Size; )
      {
          if(nums1[i1]<=nums2[i2])
          {
              if(counter==index||counter==index1)
              {
                  median+=nums1[i1];
                  if(flag==1)
                  {
                      return median;
                  }
              }
              i1++;
          }
          else
          {
              if(counter==index||counter==index1)
              {
                  median+=nums2[i2];
                  if(flag==1)
                  {
                      return median;
                  }
              }
              i2++;
          }
          counter++;
      }
      while(i1<nums1Size)
      {
          if(counter==index||counter==index1)
              {
                  median+=nums1[i1];
                  if(flag==1)
                  {
                      return median;
                  }
              }
              i1++;
              counter++;
      }
      while(i2<nums2Size)
      {
          if(counter==index||counter==index1)
              {
                  median+=nums2[i2];
                  if(flag==1)
                  {
                      return median;
                  }
              }
              i2++;
              counter++;
      }
      if(flag==0){return (float)median/2;}
      return (float)median;
  }
