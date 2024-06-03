
  int reverse(int x){
      long long int result,temp;
      result=0;
      temp=x;
      while(temp){
          result=(temp%10)+result*10;
          temp/=10;
      }
      if(result>pow(2,31)-1){
          return 0;
      }else if(result<-1*pow(2,31)){
          return 0;
      }else{
          return result;
      }
  }
