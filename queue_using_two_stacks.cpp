/*
 * Challenges: https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
 */

#include <stdio.h>

int queue[100000];
int front, end;

int main () {
  int q;

  front = end = 0;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int cmd;
    scanf("%d", &cmd);

    if (cmd == 1) {
      int value;
      scanf("%d", &value);
      queue[end++] = value;
    } else if (cmd == 2) {
      if (front < end) {
        ++front;
      }
    } else if (cmd == 3) {
      printf("%d\n", queue[front]);
    }
  }

  return 0;
}

