/*
 * Challenges: https://www.hackerrank.com/challenges/swap-nodes-algo/problem
 */
#include <stdio.h>

struct Node {
  int depth;
  int lc;
  int rc;
};

struct Node buffer[1025];
int arr[1025];
int m;

void dfs(int index) {
  if (index == -1) {
    return;
  }
  dfs(buffer[index].lc);
  arr[m++] = index;
  dfs(buffer[index].rc);
}

int main () {
  int n;

  scanf("%d", &n);
  buffer[1].depth = 1;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    buffer[i].lc = a;
    buffer[i].rc = b;
    if (a != -1) {
      buffer[a].depth = buffer[i].depth + 1;
    }
    if (b != -1) {
      buffer[b].depth = buffer[i].depth + 1;
    }
  }

  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= n; ++j) {
      if (buffer[j].depth % k == 0) {
        int tmp = buffer[j].lc;
        buffer[j].lc = buffer[j].rc;
        buffer[j].rc = tmp;
      }
    }

    m = 0;
    dfs(1);
    for (int j = 0; j < m; ++j) {
      if (j) {
        printf(" ");
      }
      printf("%d", arr[j]);
    }
    printf("\n");
  }

  return 0;
}

