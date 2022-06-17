/*
 * Challenges: https://www.hackerrank.com/challenges/game-of-two-stacks/problem
 */

#include <stdio.h>

long long sum_a[100000];

int main () {
  int g = 0;

  scanf("%d", &g);
  for (int cas = 0; cas < g; ++cas) {
    int n = 0;
    int m = 0;
    int x = 0;
    scanf("%d %d %d", &n, &m, &x);

    int iter_a = -1;
    for (int i = 0; i < n; ++i) {
      int a = 0;
      scanf("%d", &a);
      long long prev = (i > 0) ? (sum_a[i - 1]) : (0);
      sum_a[i] = prev + a;
      if (sum_a[i] <= x) {
        iter_a = i;
      }
    }
    int ans = iter_a + 1;
    long long sum_b = 0;
    for (int i = 0; i < m; ++i) {
      int b = 0;
      scanf("%d", &b);
      sum_b += b;
      for (; iter_a >= 0 && sum_a[iter_a] + sum_b > x; --iter_a) {}
      if (i + 1 + iter_a + 1 > ans && sum_b <= x) {
        ans = i + 1 + iter_a + 1;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}

