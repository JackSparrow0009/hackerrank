/*
 * Challenges: https://www.hackerrank.com/challenges/maximum-element/problem
 */
#include <stdio.h>

static int stack[100000];
static int maximum[100000];
static int top;

int main () {
  int n;

  top = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int cmd;
    scanf("%d", &cmd);

    if (1 == cmd) {
      int x;
      int new_max;
      scanf("%d", &x);
      if (top < 0 || maximum[top] < x) {
        new_max = x;
      } else {
        new_max = maximum[top];
      }
      stack[++top] = x;
      maximum[top] = new_max;
    } else if (2 == cmd) {
      if (top >= 0) {
        --top;
      }
    } else if (3 == cmd) {
      printf("%d\n", maximum[top]);
    } else {
      printf("unknown cmd: %d\n", cmd);
    }
  }
  return 0;
}

