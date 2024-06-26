
  char* intToRoman(int num) {
      char *c[4][10]={
              {"","I","II","III","IV","V","VI","VII","VIII","IX"},
              {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
              {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
              {"","M","MM","MMM"}
          };
      char *ret=(char*)malloc(sizeof(char)*20);
      int count=0;
      char *temp=c[3][num/1000];
      while(*temp!=' '){
          ret[count++]=*temp;
          temp++;
      }
      temp=c[2][num/100%10];
      while(*temp!=' '){
          ret[count++]=*temp;
          temp++;
      }
      temp=c[1][num/10%10];
      while(*temp!=' '){
          ret[count++]=*temp;
          temp++;
      }
      temp=c[0][num%10];
      while(*temp!=' '){
          ret[count++]=*temp;
          temp++;
      }
      ret[count++]=' ';
      return ret;
  }
