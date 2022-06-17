/*
 * Challenges: https://www.hackerrank.com/challenges/electronics-shop/problem
 */
#include <stdio.h>

int x[1000];
int y[1000];

int main () {
  int b, m, n;
  scanf("%d %d %d", &b, &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d", &y[i]);
  }

  int res = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int tmp = x[i] + y[j];
      if (tmp <= b && tmp > res) {
        res = tmp;
      }
    }
  }

  printf("%d\n", res);
  return 0;
}

