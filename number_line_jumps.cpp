/*
 * https://www.hackerrank.com/challenges/kangaroo/problem
 */
#include <stdio.h>

// x1 + k * v1 = x2 + k * v2
// k = (x2 - x1) / (v1 - v2);
int main () {
  int x1, x2, v1, v2;
  int res;

  scanf("%d %d %d %d", &x1, &v1, &x2, &v2);
  if (v1 == v2) {
    if (x1 == x2) {
      res = 1;
    } else {
      res = 0;
    }
  }

  int d_x = x2 - x1;
  int d_v = v2 - v1;

  if (d_x * d_v >= 0) {
    res = 0;
  } else {
    if (d_v < 0) {
      d_v = -d_v;
    }
    if (d_x < 0) {
      d_x = -d_x;
    }
    if (d_x % d_v == 0) {
      res = 1;
    } else {
      res = 0;
    }
  }

  printf("%s\n", res ? "YES" : "NO");

  return 0;
}

