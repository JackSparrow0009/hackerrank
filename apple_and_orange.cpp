/*
 * Challenges: https://www.hackerrank.com/challenges/apple-and-orange/problem
 */

#include <stdio.h>

int main () {
  int s, t;
  int a, b;
  int m, n;

  scanf("%d %d", &s, &t);
  scanf("%d %d", &a, &b);
  scanf("%d %d", &m, &n);

  int res1 = 0;
  int res2 = 0;

  for (int i = 0; i < m; ++i) {
    int offset = 0;
    scanf("%d", &offset);
    if (a + offset >= s && a + offset <= t) {
      ++res1;
    }
  }

  for (int i = 0; i < n; ++i) {
    int offset = 0;
    scanf("%d", &offset);
    if (b + offset >= s && b + offset <= t) {
      ++res2;
    }
  }

  printf("%d\n%d\n", res1, res2);

  return 0;
}

