
  #include <stdio.h>

  bool isPalindrome(int x){

      char x_str[12];

      // convert to str
      sprintf(x_str, "%d", x);

      int i = 0, j = strlen(x_str)-1;

      while (i < j) {
          if (x_str[i] != x_str[j])
              return false;
          i++;
          j--;
      }
      return true;
  }
