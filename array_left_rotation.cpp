/*
 * Challenges: https://www.hackerrank.com/challenges/array-left-rotation/problem
 */
#include <stdio.h>
#include <vector>

using std::vector;

int main() {
  int n, d;
  static int arr[100000];

  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (i) {
      printf(" ");
    }
    printf("%d", arr[(d + i) % n]);
  }
  return 0;
}

