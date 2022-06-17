/*
 * Challenges: https://www.hackerrank.com/challenges/bon-appetit/problem
 */
#include <stdio.h>

int bill[100000];

int main () {
  int n, k, b;
  int sum = 0;

  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &bill[i]);
    sum += bill[i];
  }

  sum -= bill[k];

  scanf("%d", &b);
  int res = b - sum / 2;

  if (res <= 0) {
    printf("Bon Appetit\n");
  } else {
    printf("%d\n", res);
  }

  return 0;
}

