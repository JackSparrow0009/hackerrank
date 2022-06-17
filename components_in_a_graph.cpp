/*
 * Challenges: https://www.hackerrank.com/challenges/components-in-graph/problem
 */

#include <stdio.h>
#include <memory.h>

int root[30001];
int count[30001];

inline int find(int x) {
  return (0 == root[x]) ? (x) : (root[x] = find(root[x]));
}

void Union(int a, int b) {
  int root_a = find(a);
  int root_b = find(b);

  if (root_a != root_b) {
    root[root_b] = root_a;
  }
}

int main () {
  int n;

  memset(root, 0, sizeof(root));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a = 0;
    int b = 0;

    scanf("%d %d", &a, &b);
    Union(a, b);
  }

  memset(count, 0, sizeof(count));
  for (int i = 1; i <= n; ++i) {
    ++count[find(i)];
    ++count[find(n + i)];
  }

  int min_set = 30001;
  int max_set = 0;
  for (int i = 1; i <= n + n; ++i) {
    if (count[i] <= 1) {
      continue;
    }
    if (count[i] > max_set) {
      max_set = count[i];
    }
    if (count[i] < min_set) {
      min_set = count[i];
    }
  }

  printf("%d %d\n", min_set, max_set);

  return 0;
}

