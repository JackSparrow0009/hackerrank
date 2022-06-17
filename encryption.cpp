/*
 * Challenges: https://www.hackerrank.com/challenges/encryption/problem
 */
#include <stdio.h>
#include <string.h>

char in[128];

int main() {
  int len = 0;
  int base = -1, range = 7;
  int row = 0, col = 0;

  scanf("%s", in);
  len = strlen(in);

  for (base = -1, range = 128; range; range >>= 1) {
    if (base + range <= len && (base + range) * (base + range) <= len) {
      base += range;
    }
  }

  if (base * base == len) {
    row = col = base;
  } else {
    row = col = base + 1;
  }

  for (int i = 0; i < col; ++i) {
    if (i) {
      printf(" ");
    }
    for (int j = 0; j < row; ++j) {
      int index = j * col + i;
      if (index >= len) {
        break;
      }

      printf("%c", in[index]);
    }
  }
  printf("\n");

  return 0;
}

