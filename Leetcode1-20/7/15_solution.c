

  int reverse(int x) {
          int reverse=0;
          while (x) {
              if (INT_MAX/10 < reverse || INT_MIN/10 > reverse)
                  return 0;
              reverse = reverse*10 + x % 10;
              x /= 10;
          }
          return reverse;
      }
  /*int sum=0,rem;
  int main(){
     int num,revNum;
        printf("enter number:");
     scanf("%d",&num);
     revNum=revNumFunction(num);//calling function to reverse the given number
     printf("the number after reverse :%d",revNum);
     return 0;
  }*/
