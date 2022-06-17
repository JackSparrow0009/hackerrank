/*
 * https://www.hackerrank.com/challenges/sherlock-and-squares/problem
 */
#include <stdio.h>

int main () {
  int t;
  int a, b;

  scanf("%d", &t);
  for (int cas = 0; cas < t; ++cas) {
    scanf("%d %d", &a, &b);

    int base_l = -1;
    int base_r = -1;
    int range = 32768;

    for (; range; range >>= 1) {
      int tmp_1 = base_l + range;
      if (tmp_1 < 32768 && tmp_1 * tmp_1 < a) {
        base_l += range;
      }
      int tmp_2 = base_r + range;
      if (tmp_2 < 32768 && tmp_2 * tmp_2 <= b) {
        base_r += range;
      }
    }

    printf("%d\n", base_r - base_l);
  }
  return 0;
}
