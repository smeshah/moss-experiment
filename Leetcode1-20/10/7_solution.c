
  bool isMatch(char *s, char *p)
  {
  	int s_len = 0, p_len = 0;
  	while(s[s_len] != 0) s_len++;
  	while(p[p_len] != 0) p_len++;
  	s_len++;p_len++;

  	bool m[p_len][s_len];
  	memset(m, 0, p_len*s_len);
  	m[0][0] = true;
  	for (int i = 1 ; i < p_len ; i++)
  		m[i][0] = i > 1 && p[i-1] == '*' && m[i-2][0] ? true : false;

  	for (int i = 1 ; i < p_len ; i++)
  	{
  		for (int j = 1 ; j < s_len ; j++)
  		{
  			if (p[i-1] != '*')
  				m[i][j] = m[i-1][j-1] && (p[i-1] == '.' || p[i-1] == s[j-1]);
  			else
  				m[i][j] = m[i-2][j] || ((m[i-2][j-1] || m[i][j-1]) && (p[i-2] == '.' || p[i-2] == s[j-1]));
  		}
  	}

  	return m[p_len-1][s_len-1];
  }
