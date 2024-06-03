
    int cmpfunc (const void * a, const void * b) {
       return ( *(int*)a - *(int*)b );
    }
    int threeSumClosest(int* nums, int numsSize, int target) {
        int i, j, k, start, end, res, result;
        int sum_c = INT_MAX;
        qsort(nums, numsSize, sizeof(int), cmpfunc); //sort for easy computation
        for(i = 0; i < numsSize; i++){
            for(k = i+1; k < numsSize; k++){
                for(j = k+1; j < numsSize; j++){
                    res = nums[i] + nums[j] + nums[k];
                    //printf("res %d
  ", res);
                    if((abs(res - target)) < sum_c){
                        sum_c = abs(res - target);
                        //printf("sum_C %d
  ", sum_c);
                        result = res;
                    }
                }
            }
        }
        return result;
    }
