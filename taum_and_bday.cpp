/*
 * Challenges: https://www.hackerrank.com/challenges/taum-and-bday/problem
 */
#include <stdio.h>

int main() {
  int cas;

  scanf("%d", &cas);
  for (int t = 0; t < cas; ++t) {
    long long b, w;
    long long x, y, z;

    scanf("%lld %lld", &b, &w);
    scanf("%lld %lld %lld", &x, &y, &z);

    if (x + z < y) {
      y = x + z;
    }
    if (y + z < x) {
      x = y + z;
    }

    printf("%lld\n", b * x + w * y);
  }
  return 0;
}

