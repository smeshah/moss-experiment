
    int maxArea(int* height, int heightSize){
    int vol=0,x;
        for(int i=0,j=heightSize-1;i<j;)
        {   printf("%d %d
  ",i,j);
            x=height[i]>=height[j]?height[j--]:height[i++];
            if(x*(j-i+1)>vol)
                vol=x*(j-i+1); 
        }
        return vol;

    }