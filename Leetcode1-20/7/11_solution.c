
  int reverse(int x){
      int res = 0;

      do {
          int c = x % 10;
          x /= 10;
          if (__builtin_mul_overflow(res, 10, &res))
              return 0;

          res += c;
      } while(x);

      return res;
  }
