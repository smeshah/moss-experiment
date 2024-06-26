
  int romanToInt(char *s) {
      int map[26] = {0, 0, 100, 500, 0, 0, 0, 0, 1, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10, 0, 0};
      int sum = 0;
      while (*s != ' ') {
          char now = *s, next = *(s + 1);
          if (next != ' ') {
              if (map[now - 'A'] < map[next - 'A']) {
                  sum += map[next - 'A'] - map[now - 'A'];
                  s += 2;
                  continue;
              }
          }
          sum += map[now - 'A'];
          s++;
      }
      return sum;
  }
