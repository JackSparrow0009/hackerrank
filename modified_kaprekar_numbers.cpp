/*
 * Challenges: https://www.hackerrank.com/challenges/kaprekar-numbers/problem
 */
#include <stdio.h>
#include <string.h>

int is_kerperka(long long x) {
  long long square = x * x;
  long long module = 10;

  for (module = 10; module <= x; module *= 10) {
  }

  return square % module + square / module == x;
}

int main() {
  int p, q;
  int has_prev = 0;

  scanf("%d %d", &p, &q);

  for (int i = p; i <= q; ++i) {
    if (is_kerperka(i)) {
      if (has_prev) {
        printf(" ");
      }
      printf("%d", i);
      has_prev = 1;
    }
  }
  if (!has_prev) {
    printf("INVALID RANGE");
  }
  printf("\n");

  return 0;
}

