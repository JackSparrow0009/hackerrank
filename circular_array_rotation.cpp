/*
 * Challenges: https://www.hackerrank.com/challenges/circular-array-rotation/problem
 */
#include <stdio.h>

int val[100000];

int main () {
  int n, k, q;

  scanf("%d %d %d", &n, &k, &q);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &val[i]);
  }

  k %= n;
  for (int i = 0; i < q; ++i) {
    int pos;
    scanf("%d", &pos);

    printf("%d\n", val[(pos - k + n) % n]);
  }
  return 0;
}
