  int myAtoi(char* str) {
      int num=0;
      int negative_flag = 0;
      int start_flag = 1;
      for(int i=0; str[i]; i++)
      {
          if(start_flag && str[i] == ' ')
              continue;
          else 
          {
              if(str[i] >= '0' && str[i] <= '9')
              {
                  start_flag = 0;
                  int pop = (str[i]-'0');
                  if(num > INT_MAX/10 || (num == INT_MAX/10) && pop > 7)
                      return INT_MAX;
                  if(num < INT_MIN/10 || (num == INT_MIN/10) && pop > 8)
                      return INT_MIN;
                  if(negative_flag)
                      num = num*10 - pop;
                  else
                      num = num*10 + pop; 
              }
              else if(start_flag && str[i] == '-' && (str[i+1] >= '0' && str[i+1] <= '9'))
              {
                  negative_flag = 1;
                  continue;
              }
              else if(start_flag && str[i] == '+' && (str[i+1] >= '0' && str[i+1] <= '9'))
                  continue;
              else
                  break;
          }
      }
      return num ? num : 0;
  }
