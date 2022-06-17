/*
 * Challenges: https://www.hackerrank.com/challenges/bigger-is-greater/problem
 */
#include <stdio.h>
#include <string.h>

char w[128];

int main() {
  int cas;
  int len;
  int old_break_point;
  int new_break_point;

  scanf("%d", &cas);
  for (int t = 0; t < cas; ++t) {
    scanf("%s", w);
    len = strlen(w);

    old_break_point = -1;
    for (int i = len - 2; i >= 0; --i) {
      if (w[i] < w[i + 1]) {
        old_break_point = i;
        break;
      }
    }

    if (old_break_point < 0) {
      printf("no answer");
    } else {
      for (int i = len - 1; i > old_break_point; --i) {
        if (w[i] > w[old_break_point]) {
          new_break_point = i;
          break;
        }
      }
      w[old_break_point] ^= w[new_break_point];
      w[new_break_point] ^= w[old_break_point];
      w[old_break_point] ^= w[new_break_point];
      for (int i = 0; i <= old_break_point; ++i) {
        printf("%c", w[i]);
      }
      for (int i = len - 1; i > old_break_point; --i) {
        printf("%c", w[i]);
      }
    }
    printf("\n");
  }

  return 0;
}

