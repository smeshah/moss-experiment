
  char * convert(char * s, int numRows){
      if(numRows==1){
          return s;
      }
      int j=0;
      char *result;
      result=(char *)calloc(1000,1);
      for(int row=0;row<numRows;row++){
          int i=row;

          while(i<strlen(s)){
               result[j++]=s[i];
              i+=(numRows-i%(numRows-1)-1)*2;
          }
      }
      printf("%s ",result);
      return result;
  }
