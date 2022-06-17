/*
 * Challenges: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem
 */
#include <stdio.h>

int c[32];

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }

  int e = 100;
  int curr = 0;
  do {
    curr = (curr + k) % n;
    --e;
    if (1 == c[curr]) {
      e -= 2;
    }
  } while (0 != curr);

  printf("%d\n", e);
  return 0;
}

