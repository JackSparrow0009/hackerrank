/*
 * Challenges: https://www.hackerrank.com/challenges/utopian-tree/problem
 */
#include <stdio.h>

int main () {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n;
    scanf("%d", &n);
    long res = 1;
    for (int j = 0; j < n; ++j) {
      if (j & 1) {
        res = res + 1;
      } else {
        res = res * 2;
      }
    }

    printf("%ld\n", res);
  }
  return 0;
}
