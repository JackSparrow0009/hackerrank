/*
 * Challenges: https://www.hackerrank.com/challenges/magic-square-forming/problem
 */
#include <stdio.h>
#include <memory.h>

int input[9];
int magic[9];
int mark[9];
int result = 0x7FFFFFFF;

int diff(int *a, int *b) {
  int ret = 0;
  for (int i = 0; i < 9; ++i) {
    if (a[i] > b[i]) {
      ret += a[i] - b[i];
    } else {
      ret += b[i] - a[i];
    }
  }
  return ret;
}

int is_magic(int *a) {
  int v1 = a[0] + a[1] + a[2];
  int v2 = a[3] + a[4] + a[5];
  int v3 = a[6] + a[7] + a[8];
  int v4 = a[0] + a[3] + a[6];
  int v5 = a[1] + a[4] + a[7];
  int v6 = a[2] + a[5] + a[8];
  int v7 = a[0] + a[4] + a[8];
  int v8 = a[2] + a[4] + a[6];

  return v1 == v2 && v1 == v3 && v1 == v4 && v1 == v5 && v1 == v6 && v1 == v7 && v1 == v8;
}

void dfs(int index) {
  if (index == 9) {
    if (is_magic(magic)) {
      int tmp = diff(input, magic);
      if (tmp < result) {
        result = tmp;
      }
    }
    return;
  }

  for (int i = 0; i < 9; ++i) {
    if (mark[i] == 0) {
      mark[i] = 1;
      magic[index] = i + 1;
      dfs(index + 1);
      mark[i] = 0;
    }
  }
}

int main () {
  for (int i = 0; i < 9; ++i) {
    scanf("%d", &input[i]);
  }

  memset(mark, 0, sizeof(mark));
  dfs(0);

  printf("%d\n", result);

  return 0;
}

