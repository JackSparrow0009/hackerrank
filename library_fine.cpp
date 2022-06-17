/*
 * https://www.hackerrank.com/challenges/library-fine/problem
 */
#include <stdio.h>

int main () {
  int y1, y2, m1, m2, d1, d2;

  scanf("%d %d %d", &d1, &m1, &y1);
  scanf("%d %d %d", &d2, &m2, &y2);

  int fine = 0;
  if (y1 < y2) {
  } else if (y1 == y2) {
    if (m1 < m2) {
    } else if (m1 == m2) {
      if (d1 > d2) {
        fine = 15 * (d1 - d2);
      }
    } else {
      fine = 500 * (m1 - m2);
    }
  } else {
    fine = 10000;
  }

  printf("%d\n", fine);
  return 0;
}

