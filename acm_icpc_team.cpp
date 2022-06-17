/*
 * Challenges: https://www.hackerrank.com/challenges/acm-icpc-team/problem
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main () {
  static char in[500][501];
  int m, n;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", in[i]);
  }

  int max = 0;
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int cover = 0;
      for (int k = 0; k < m; ++k) {
        if (in[i][k] == '1' || in[j][k] == '1') {
          ++cover;
        }
      }
      if (cover > max) {
        max = cover;
        cnt = 1;
      } else if (cover == max) {
        ++cnt;
      }
    }
  }

  printf("%d\n%d\n", max, cnt);
  return 0;
}

