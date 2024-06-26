
  int reverse(int x){
  	int cp_x = x;

  	if( x<10 && x>-10 ){
  		return x;
  	}

  	if (x >= INT32_MAX|| x <= INT32_MIN){
  		return 0;
  	}

  	int neg = 0;

  	if (cp_x<0){
  		neg = 1;
  		cp_x *= -1;
  	}

  	int array[10];
  	int count = 0;
  	int digit;


  	while(cp_x){
  		digit = cp_x%10;
  		array[count] = digit;
  		cp_x /= 10;
  		count+=1;
  	}



  	int max[10] = {2,1,4,7,4,8,3,6,4,7};

  	int is_max = 1;

  	if(count < 10){
  		is_max = 0;
  	}

  	int re = 0;
  	for (int i = 0; i < count; i++){
  		if (is_max){
  			if(array[i]<max[i]){
  				is_max = 0;
  			}else if(array[i] > max[i]){
  				return 0;
  			}
  		}
  		re += array[i]*pow(10,count-i-1);
  	}
  	if (neg){
  		re*=-1;
  	}
  	return re;
  }

