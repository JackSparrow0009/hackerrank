/*
 * Challenges: https://www.hackerrank.com/challenges/sock-merchant/problem
 */
#include <stdio.h>
#include <memory.h>

int bin[101];

int main () {
  int n;

  memset(bin, 0, sizeof(bin));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int value;
    scanf("%d", &value);
    ++bin[value];
  }
  int res = 0;
  for (int i = 0; i < 101; ++i) {
    res += bin[i] / 2;
  }

  printf("%d\n", res);

  return 0;
}


