

  int reverse(int x){
      int digit, ne = 0;
      long reverse = 0;
      bool ng = (x < 0);

      if(ng) {
          if((x * -1) >= INT_MAX) {
              return 0;
          } else {
              x = x * -1;    
          }
      }

      while(x != 0) {
          if (ng &&  reverse < -0x7FFFFFFF/10) return 0;
          if (!ng &&  reverse > 0x7FFFFFFF/10) return 0;
          digit = x%10;
          x = x/10;
          reverse = (reverse * 10) + digit;
          if (ng &&   x%10 < -0x7FFFFFFF-reverse) return 0;
          if (!ng &&  x%10 > 0x7FFFFFFF-reverse) return 0;
      }

      if ((ng &&   x%10 < -0x7FFFFFFF-reverse) || (!ng &&  x%10 > 0x7FFFFFFF-reverse)) {
          return 0;
      } else {
          if(!ng) {
              return reverse;    
          } else {
              reverse = reverse * -1;
              if(reverse <= INT_MIN) {
                  return 0;
              } else {
                  return reverse;    
              }
          }   
      }
  }
