
  int romanToInt(char * s){

      int sum=0,len=0,last=0,cur,i;
      for (int i=0;s[i]!=' ';i++)
          len++;

      for (i=len-1;i>=0;i--)
      {
          cur=0;
          if(s[i]=='I')
              cur=1;
          else 
          if(s[i]=='V')
              cur=5;
          else
          if(s[i]=='X')
              cur=10;
          else
          if(s[i]=='L')
               cur=50;

          else
          if(s[i]=='C')
              cur=100;
          else
          if(s[i]=='D')
              cur=500;
          else 
          if(s[i]=='M')
              cur=1000;



          if(cur>=last){


              sum+=cur;
              last=cur;
          }
          else{
              sum-=cur;
              last=cur;
          }





      }
      return sum;

  }
