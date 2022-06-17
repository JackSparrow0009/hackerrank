/*
 * Challenges: https://www.hackerrank.com/challenges/equality-in-a-array/problem
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main () {
  static int arr[100];
  static int cnt[101];
  int n;

  memset(cnt, 0, sizeof(cnt));
  int max = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    ++cnt[arr[i]];
    if (cnt[arr[i]] > max) {
      max = cnt[arr[i]];
    }
  }

  printf("%d\n", n - max);

  return 0;
}

