
  static bool dfs(char *s, char *p, char c)
  {
      while (*s && (c == '.' || *s == c))
          if (dfs(s++, p, 0))
              return true;
      while (*p) {
          if (*(p+1) == '*')
              return dfs(s, p+2, *p);
          if (*s && (*p == '.' || *s == *p)) {
              s++;
              p++;
          } else {
              return false;
          }
      }
      if (*s == ' ' && *p == ' ')
          return true;
      else
          return false;
  }

  bool isMatch(char * s, char * p){
      return dfs(s, p, 0);
  }
