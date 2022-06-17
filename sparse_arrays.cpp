/*
 * Challenges: https://www.hackerrank.com/challenges/sparse-arrays/problem
 */
#include <stdio.h>
#include <string.h>

int main() {
  int n, q;
  static char str[1000][21];
  static char qry[1000][21];

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", &str[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%s", &qry[i]);
  }

  for (int i = 0; i < q; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (strcmp(str[j], qry[i]) == 0) {
        ++cnt;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}

