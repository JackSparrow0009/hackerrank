/*
 * Challenges: https://www.hackerrank.com/challenges/largest-rectangle/problem
 */

#include <stdio.h>

int h[100000];
int l_bound[100000];
int r_bound[100000];

int stack[100000];
int top;

int main () {
  int n = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }

  top = -1;
  for (int i = 0; i < n; ++i) {
    for (; top >= 0 && h[i] <= h[stack[top]]; --top) {}
    l_bound[i] = (top >= 0) ? (stack[top] + 1) : (0);
    stack[++top] = i;
  }

  top = -1;
  for (int i = n - 1; i >= 0; --i) {
    for (; top >= 0 && h[i] <= h[stack[top]]; --top) {}
    r_bound[i] = (top >= 0) ? (stack[top] - 1) : (n - 1);
    stack[++top] = i;
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long area = (long long)(r_bound[i] - l_bound[i] + 1) * (long long)(h[i]);
    if (area > ans) {
      ans = area;
    }
  }
  printf("%lld\n", ans);

  return 0;
}

