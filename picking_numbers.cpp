/*
 * Challenges: https://www.hackerrank.com/challenges/picking-numbers/problem
 */
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *p1, const void *p2) {
  return (*(const int *)p1) > (*(const int*)p2) ? 1 : -1;
}

int main () {
  int n;
  static int a[100];

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  qsort(a, n, sizeof(int), cmp);

  int result = 0;
  int status = 0;
  int count1 = 0;
  int count2 = 0;

  for (int i = 0; i < n; ++i) {
    if (status == 0) {
      status = 1;
      count1 = 1;
      count2 = 0;
    } else if (status == 1) {
      if (a[i] == a[i - 1]) {
        ++count1;
      } else if (a[i] == a[i - 1] + 1) {
        status = 2;
        ++count2;
      } else {
        count1 = 1;
        count2 = 0;
        status = 1;
      }
    } else if (status == 2) {
      if (a[i] == a[i - 1]) {
        ++count2;
      } else if (a[i] == a[i - 1] + 1) {
        count1 = count2;
        count2 = 1;
        status = 2;
      } else {
        count1 = 1;
        count2 = 0;
        status = 1;
      }
    }
    if (count1 + count2 > result) {
      result = count1 + count2;
    }
  }

  printf("%d\n", result);
  return 0;
}

