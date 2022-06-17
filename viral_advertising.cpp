/*
 * Challenges: https://www.hackerrank.com/challenges/strange-advertising/problem
 */
#include <stdio.h>

int main () {
  int n;
  long a, b, c;

  a = 5;
  b = 2;
  c = 2;

  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    long ta = b * 3;
    long tb = ta / 2;
    long tc = c + tb;

    a = ta;
    b = tb;
    c = tc;
  }

  printf("%ld\n", c);
  return 0;
}

