
  #include <stdio.h>
  #include <stdlib.h>

  bool isPalindrome(int x)
  {
      if (x < 0)
          return false;

      if (x == 0)
          return true;

      bool palindrome = true;

      int xSize = floor(log10(abs(x))) + 1;
      char xString[xSize + 1];
      char xStringReversed[xSize + 1];

      sprintf(xString, "%d", x);

      for (int i = 0; i < xSize; i++)
      {
          if (xString[i] != xString[xSize - i - 1])
          {
              palindrome = false;
              goto breakSearch;
          }
      }

      breakSearch:

      return palindrome;
  }
