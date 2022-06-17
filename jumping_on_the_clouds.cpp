/*
 * Challenges: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
 */

#include <stdio.h>

int main () {
  static int arr[100];
  static int dp[100];

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  dp[0] = 0;
  dp[1] = (arr[1] == 0 ? 1 : 1000);

  for (int i = 2; i < n; ++i) {
    if (arr[i] == 1) {
      dp[i] = 1000;
    } else {
      dp[i] = (dp[i - 2] > dp[i - 1] ? dp[i - 1] : dp[i - 2]) + 1;
    }
  }

  printf("%d\n", dp[n - 1]);
  return 0;
}
