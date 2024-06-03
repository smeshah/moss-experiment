

  int myAtoi(char * str){
      int sstr = strlen(str);
      int i;
      for(i=0;i<sstr;i++){
          if(str[i]>='0'&&str[i]<='9'||str[i]=='+'){
              return atol(str)>INT_MAX? INT_MAX : atoi(str);
          }
          else if(str[i]=='-'){
              return atol(str)<INT_MIN? INT_MIN : atoi(str);
          }
          else if(str[i]==' ')
              continue;    
          else
              return 0;
      }
      return 0;
  }

