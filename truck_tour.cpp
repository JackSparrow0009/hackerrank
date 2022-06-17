/*
 * Challenges: https://www.hackerrank.com/challenges/truck-tour/problem
 */

#include <stdio.h>

int arr[100000];

int main () {
  int n = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a = 0;
    int b = 0;

    scanf("%d %d", &a, &b);
    arr[i] = a - b;
  }

  long long sum = 0;
  int start = -1;
  for (int i = 0; i < n + n; ++i) {
    int ii = i % n;
    sum += arr[ii];

    if (sum < 0) {
      sum = 0;
      start = i;
    }

    if (i - start == n) {
      break;
    }
  }

  printf("%d\n", start + 1);

  return 0;
}

