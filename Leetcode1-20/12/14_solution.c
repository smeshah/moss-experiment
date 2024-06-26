



  char * intToRoman(int num){

   char *opt = (char*)malloc(50*(sizeof(char)));
   opt[0] = ' ';

   char table[16][2]= {
   "", "", "",     "M",
   "CM", "D", "CD","C",
   "XC", "L", "XL", "X",
   "IX", "V", "IV","I"};

  int hash[10] = {3,3,3,3,2,1,4,4,4,0};
  int rec = num;
  int money;
  int i = 0;
  int mod; 
  int divisor;
  int compensate = 1;
  uint8_t index = 0;
  // int total = 0;

  while(rec > 0 && i < 4)
  {
      divisor  =  pow(10,(3-i));
      mod = rec / divisor;
      if(mod > 0)
      {
          money = hash[mod];
          index = (4*i) + money;
          switch(money)
          {
              case 2:
              case 0:
              strncat(opt,table[index],2);
              break;
              case 1:
              strncat(opt,table[index],1);
              break;
              case 4:
              strncat(opt,table[index -3],1);
              case 3:
              compensate = (money == 3)?mod:mod-5;
              for(uint8_t k = 0;  k < compensate; k++)
              {
                  if(money == 4)
                  strncat(opt,table[index -1],1);
                  else
                  strncat(opt,table[index],1);
              }
              break;
          }
      }
      rec = rec - (divisor * mod);
      i++;
  }

   return  opt;


  }
