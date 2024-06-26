
  char *start, *end;
  char *cursor = s, *sub_start = s;
  int max_len = 1;

  while(*cursor){
      start = cursor; end = cursor;

      // skip duplicate
      while(*(end+1) && *(end+1)==*end) end++;

      cursor = end + 1;

      // set the boundary coundition
      while(*(end+1) && (start>s) && *(end+1)==*(start-1)){
          start--; end++;
      }

      if(end - start + 1 > max_len){
          max_len = end - start + 1;
          sub_start = start;
      }

  }
  // char *return_substr = (char*)malloc((max_len+1)*sizeof(char));
  // memset(return_substr, 0, max_len+1);
  char *return_substr = (char *) calloc(max_len + 1, sizeof(char));
  strncpy(return_substr, sub_start, max_len);
  return return_substr;

