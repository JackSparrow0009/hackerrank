/*
 * Challenges: https://www.hackerrank.com/challenges/find-digits/problem
 */
#include <stdio.h>

int main () {
  int t, n;

  scanf("%d", &t);
  for (int cas = 0; cas < t; ++cas) {
    scanf("%d", &n);

    int cnt = 0;
    for (int x = n; x; x /= 10) {
      if (x % 10 != 0 && n % (x % 10) == 0) {
        ++cnt;
      }
    }

    printf("%d\n", cnt);
  }
  return 0;
}

