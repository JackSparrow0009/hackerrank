/*
 * Challenges: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
 */
#include <stdio.h>

int arr[100];

int main () {
  int n, k;

  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((arr[i] + arr[j]) % k == 0) {
        ++cnt;
      }
    }
  }

  printf("%d\n", cnt);
  return 0;
}

