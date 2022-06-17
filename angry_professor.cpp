/*
 * Challenges: https://www.hackerrank.com/challenges/angry-professor/problem
 */

#include <stdio.h>

int main () {
  int t;

  scanf("%d", &t);
  for (int case_id = 0; case_id < t; ++case_id) {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      if (x <= 0) {
        --k;
      }
    }

    printf("%s\n", (k > 0 ? "YES" : "NO"));
  }

  return 0;
}


