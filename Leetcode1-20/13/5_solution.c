
  int value(char l)
  {
      if (l=='I')
          return 1;
      else if(l=='V')
          return 5;
      else if(l=='X')
          return 10;
      else if(l=='L')
          return 50;
      else if(l=='C')
          return 100;
      else if(l=='D')
          return 500;
      else 
          return 1000;

  }

  int romanToInt(char * s){
      int n=strlen(s);
      int ans=value(s[n-1]);
      for(int i=n-2;i>=0;i--)
      {
          if(value(s[i])>=value(s[i+1]))
              ans+=value(s[i]);
          else
              ans-=value(s[i]);
      }
      return ans;
  }
