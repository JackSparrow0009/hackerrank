/*
 * Challenges: https://www.hackerrank.com/challenges/permutation-equation/problem
 */
#include <stdio.h>

int p[51];
int a[51];
int main () {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }

  for (int i = 1; i <= n; ++i) {
    int x = p[p[i]];
    a[x] = i;
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d\n", a[i]);
  }

  return 0;
}

