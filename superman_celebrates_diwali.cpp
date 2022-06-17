/*
 * Challenges: https://www.hackerrank.com/challenges/superman-celebrates-diwali/problem
 */
#include <stdio.h>
#include <memory.h>

typedef int int32;

static int32 dp[1901][1901];
static int32 best[1901];
static int32 n_people[1901][1901];

int main () {
  int32 h = 0;
  int32 n = 0;
  int32 i = 0;

  while (scanf("%d %d %d", &h, &n, &i) != EOF) {
    memset(dp, 0, sizeof(dp));
    memset(best, 0, sizeof(best));
    memset(n_people, 0, sizeof(n_people));

    for (int32 k1 = 0; k1 < h; ++k1) {
      int32 u = 0;
      scanf("%d", &u);
      for (int32 k2 = 0; k2 < u; ++k2) {
        int32 uij;
        scanf("%d", &uij);
        ++n_people[k1][uij];
      }
    }

    for (int32 k1 = 1; k1 <= n; ++k1) {
      for (int32 k2 = 0; k2 < h; ++k2) {
        dp[k2][k1] = dp[k2][k1 - 1] + n_people[k2][k1];

        if (k1 > i && best[k1 - i] + n_people[k2][k1] > dp[k2][k1]) {
          dp[k2][k1] = best[k1 - i] + n_people[k2][k1];
        }

        if (dp[k2][k1] > best[k1]) {
          best[k1] = dp[k2][k1];
        }
      }
    }

    printf("%d\n", best[n]);
  }
  return 0;
}


