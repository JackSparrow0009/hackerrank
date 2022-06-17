/*
 * Challenges: https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

static int mat[100][100];
static long long sum_x[100];
static long long sum_y[100];

int cmp (const void *p1, const void *p2) {
  return (*(const long long *)p1) > (*(const long long *)p2) ? 1 : -1;
}

int main () {
  int cas;

  scanf("%d", &cas);
  for (int t = 0; t < cas; ++t) {
    int n;
    scanf("%d", &n);

    memset(sum_x, 0, sizeof(sum_x));
    memset(sum_y, 0, sizeof(sum_y));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &mat[i][j]);
        sum_x[i] += mat[i][j];
        sum_y[j] += mat[i][j];
      }
    }

    qsort(sum_x, n, sizeof(sum_x[0]), cmp);
    qsort(sum_y, n, sizeof(sum_y[0]), cmp);

    int is_possible = true;
    for (int i = 0; i < n; ++i) {
      if (sum_x[i] != sum_y[i]) {
        is_possible = false;
        break;
      }
    }

    printf("%s\n", is_possible ? "Possible" : "Impossible");
  }
  return 0;
}

