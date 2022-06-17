/*
 * Challeges: https://www.hackerrank.com/challenges/the-hurdle-race/problem
 */
#include <stdio.h>
#include <stdlib.h>

int main () {
  int n, k, height;

  scanf("%d %d", &n, &k);

  int max = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &height);
    if (height > max) {
      max = height;
    }
  }

  printf("%d\n", k >= max ? 0 : max - k);
  return 0;
}

