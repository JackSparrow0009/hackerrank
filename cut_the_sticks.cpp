/*
 * Challenges: https://www.hackerrank.com/challenges/cut-the-sticks/problem
 */
#include <stdio.h>
#include <stdlib.h>

int a[1000];

int cmp(const void *p1, const void *p2) {
  return (*(const int *)p1) > (*(const int *)p2) ? 1 : -1;
}

int main () {
  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  qsort(a, n, sizeof(int), cmp);

  int length = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > length) {
      printf("%d\n", n - i);
      length = a[i];
    }
  }
  return 0;
}
