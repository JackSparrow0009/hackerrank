/*
 * Challenges: https://www.hackerrank.com/challenges/down-to-zero-ii/problem
 */

#include <stdio.h>
#include <memory.h>
#include <queue>

#define MAX 1000001

using std::queue;
int ans[MAX];

int main () {
  for (int i = 0; i < MAX; ++i) {
    ans[i] = i;
  }

  for (int i = 0; i < MAX; ++i) {
    for (int j = 0; j <= i && i * j < MAX; ++j) {
      if (ans[i * j] > ans[i] + 1) {
        ans[i * j] = ans[i] + 1;
      }
      if (ans[i + 1] > ans[i] + 1) {
        ans[i + 1] = ans[i] + 1;
      }
    }
  }

  int q = 0;
  scanf("%d", &q);
  for (int cas = 0; cas < q; ++cas) {
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }

  return 0;
}

