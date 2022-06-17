/*
 * Challenges: https://www.hackerrank.com/challenges/non-divisible-subset/problem
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int bin[100];

int main () {
  int n, k;

  scanf("%d %d", &n, &k);
  memset(bin, 0, sizeof(bin));
  for (int i = 0; i < n; ++i) {
    int tmp;
    scanf("%d", &tmp);
    ++bin[tmp % k];
  }

  int ans = 0;
  for (int i = 1; i <= k / 2; ++i) {
    if (i != k - i) {
      ans += (bin[i] > bin[k - i] ? bin[i] : bin[k - i]);
    } else {
      ans += (bin[i] > 0 ? 1 : 0);
    }
  }

  if (bin[0]) {
    ++ans;
  }

  printf("%d\n", ans);

  return 0;
}
