
  double findMedianSortedArrays(int* n1, int s1, int* n2, int s2){
          int s3 = s1+s2;
      int *n3=(int *) malloc(sizeof(int)*s3);
      int j=0, k=0;
      for (int i=0;i<s3;i++) {
          if(k==s2 && j<s1){
              n3[i]=n1[j];
              j++;
          }
          else if(j==s1 && k<s2) {
              n3[i]=n2[k];
              k++;
          }
          else if(n2[k]<n1[j]) {
              n3[i]=n2[k];
              k++;
          }
          else if(n1[j]<=n2[k]){
              n3[i] = n1[j];
              j++;
          }
      }
      if (s3==1)
          return n3[0];
     else if (s3%2==0) {
         int i=s3/2;
         double m = (n3[i-1]+n3[i])/(double) 2;
         return m;
     }
      else {
          return n3[s3/2];
      }
      return -1;
  }
