/*
 * Challenges: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
 */
#include <stdio.h>
#include <stdlib.h>

int main () {
  static int score[200000];
  int alice;

  int n, m;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &score[i]);
  }

  int new_n = 0;
  for (int i = 1; i < n; ++i) {
    if (score[i] != score[new_n]) {
      score[++new_n] = score[i];
    }
  }
  ++new_n;

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &alice);

    int base  = -1;
    int range = 1 << 20;

    for ( ; range; range >>= 1) {
      if (base + range < new_n && score[base + range] > alice) {
        base += range;
      }
    }

    printf("%d\n", base + 2);
  }

  return 0;
}

