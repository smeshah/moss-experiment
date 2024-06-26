
  /*
   * memo[len1][len2] indicate whether s's first len1 chars and p's first len2 chars matchs
   * true for matched; false for unmatched; -1 for not initialized
   */
  int memo[21][31];

  bool __is_char_match(char a, char b)
  {
          if (a == b || b == '.')
                  return true;
          return false;
  }

  bool is_char_match(char *s, int len1, char *p, int len2)
  {
          if (len1 <= 0 || len2 <= 0)
                  return false;
          return __is_char_match(s[len1 - 1], p[len2 - 1]);
  }

  bool __is_match(char *s, int len1, char *p, int len2)
  {
          if (len1 < 0 || len2 < 0)
                  return false;
          if (memo[len1][len2] != -1)
                  return memo[len1][len2];

          if (p[len2 - 1] == '*') {
                  if (is_char_match(s, len1, p, len2 - 1)) {
                  		/*
                  		 * if current char is '* and prev char matches, either we match zero char in s;
                  		 * or we match one char in s (multiple chars match situation will be considered
                           * in following recursive calls).
                  		 */
                          if (__is_match(s, len1, p, len2 - 2) || __is_match(s, len1 - 1, p, len2))
                                  memo[len1][len2] = true;
                          else
                                  memo[len1][len2] = false;
                  } else {
                          if (__is_match(s, len1, p, len2 - 2))
                                  memo[len1][len2] = true;
                          else
                                  memo[len1][len2] = false;
                  }
          } else {
                  if (is_char_match(s, len1, p, len2) && __is_match(s, len1 - 1, p, len2 - 1))
                          memo[len1][len2] = true;
                  else
                          memo[len1][len2] = false;
          }

          return memo[len1][len2];
  }

  bool isMatch(char * s, char * p)
  {
          int len1 = strlen(s);
          int len2 = strlen(p);

          int i, j;
          for (i = 0; i < 21; i++) {
                  memo[i][0] = false; // if 'p' is empty while 's' is not, apparently they won't match
                  for (j = 1; j < 31; j++)
                          memo[i][j] = -1;
          }
          memo[0][0] = true; // two empty strs matches

          return __is_match(s, len1, p, len2);
  }
