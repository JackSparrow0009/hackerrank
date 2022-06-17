/*
 * Challenges: https://www.hackerrank.com/challenges/migratory-birds/problem
 */
#include <stdio.h>

int main () {
  int n;
  scanf("%d", &n);

  static int cnt[6] = {0, 0, 0, 0, 0, 0};
  for (int i = 0; i < n; ++i) {
    int type;
    scanf("%d", &type);
    ++cnt[type];
  }

  int max_id = 1;
  for (int i = 2; i < 6; ++i) {
    if (cnt[i] > cnt[max_id]) {
      max_id = i;
    }
  }

  printf("%d\n", max_id);

  return 0;
}

