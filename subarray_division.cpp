/*
 * Challenges: https://www.hackerrank.com/challenges/the-birthday-bar/problem
 */
#include <stdio.h>

static int arr[100];

int main () {
  int n, d, m;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  scanf("%d %d", &d, &m);

  int sum = 0;
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    sum += arr[i];
    if (i >= m) {
      sum -= arr[i - m];
      if (sum == d) {
        ++cnt;
      }
    } else if (i + 1 == m && sum == d) {
      ++cnt;
    }
  }

  printf("%d\n", cnt);

  return 0;
}

