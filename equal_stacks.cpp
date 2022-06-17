/*
 * Challenges: https://www.hackerrank.com/challenges/equal-stacks/problem
 */

#include <stdio.h>

#define N (3)

int main () {
  static int n[N];
  static int s[N];
  static int p[N];
  static int a[N][100000];

  for (int i = 0; i < N; ++i) {
    scanf("%d", &n[i]);
    s[i] = 0;
    p[i] = 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      scanf("%d", &a[i][j]);
      s[i] += a[i][j];
    }
  }

  while (1) {
    int min = 2147483647;
    int max = 0;

    for (int i = 0; i < N; ++i) {
      if (min > s[i]) {
        min = s[i];
      }
      if (max < s[i]) {
        max = s[i];
      }
    }

    if (min == max) {
      break;
    }

    for (int i = 0; i < N; ++i) {
      while (p[i] < n[i] && s[i] > min) {
        s[i] -= a[i][p[i]++];
      }
    }
  }

  printf("%d\n", s[0]);

  return 0;
}

