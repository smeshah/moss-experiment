
  bool isMatch(char * s, char * p) {
      int s_len = strlen(s);
      int p_len = strlen(p);

      bool dp[s_len + 1][p_len + 1];
      for (int i = 0; i <= s_len; i++) {
          for (int j = 0; j <= p_len; j++) {
              dp[i][j] = false;
          }
      }
      dp[0][0] = true;

      for (int j = 2; j <= p_len; j += 2) {
          if (*(p+j-1) == '*') {
              dp[0][j] = dp[0][j-2];
          }
      }

      for (int i = 1; i <= s_len; i++) {
          for (int j = 1; j <= p_len; j++) {
              if (*(p+j-1) == '*') {
                  dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (*(s+i-1) == *(p+j-2) || *(p+j-2) == '.'));
              } else {
                  dp[i][j] = dp[i-1][j-1] && (*(s+i-1) == *(p+j-1)|| *(p+j-1) == '.');
              }
          }
      }

      return dp[s_len][p_len];
  }

