
  #define hash_new(h, max)        int h##Pos[max]; int h##Neg[max];                                   for (int i = 0; i < max; i++) { h##Pos[i] = -1; h##Neg[i] = -1; }
  #define hash_get(h, key)        ((key) < 0? h##Neg[key]: h##Pos[key])
  #define hash_set(h, key, val)   if ((key) < 0) h##Neg[key] = val; else h##Pos[key] = val
  #define hash_exist(h, key)      (hash_get(h, key) != -1)

  int* twoSum(int* nums, int numsSize, int target) {
      if (!nums || numsSize <= 0) return NULL;
      hash_new(map, 100000);

      for (int i = 0; i < numsSize; i++) {
          if (hash_exist(map, target - nums[i])) {
              int *result = malloc(sizeof(int) * 2);
              result[0] = hash_get(map, target - nums[i]);
              result[1] = i;
              return result;
          }
          hash_set(map, nums[i], i); 
      }
      return NULL;
  }
