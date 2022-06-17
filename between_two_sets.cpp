/*
 * Challenges: https://www.hackerrank.com/challenges/between-two-sets/problem
 */
#include <stdio.h>

static int a[100];
static int b[100];

int gcd(int x, int y) {
  if (x == 0) return y;
  if (y == 0) return x;

  return gcd(y, x % y);
}

int lcm(int x, int y) {
  return x * y / gcd(x, y);
}

int main () {
  int n, m;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }

  int gcd_a = a[0];
  for (int i = 1; i < n; ++i) {
    gcd_a = gcd(gcd_a, a[i]);
  }
  int gcd_b = b[0];
  for (int i = 1; i < m; ++i) {
    gcd_b = gcd(gcd_b, b[i]);
  }

  int lcm_a = a[0];
  for (int i = 1; i < n; ++i) {
    lcm_a = lcm(lcm_a, a[i]);
  }

  int cnt = 0;
  for (int i = lcm_a; i <= gcd_b; i += lcm_a) {
    if (gcd_b % i == 0) {
      ++cnt;
    }
  }
  printf("%d\n", cnt);

  return 0;
}

