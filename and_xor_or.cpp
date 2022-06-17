/*
 * Challenges: https://www.hackerrank.com/challenges/and-xor-or/problem
 */
#include <stdio.h>

int main () {
  static int n;
  static int arr[1000000];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  static int stack[1000000];
  static int top = -1;
  static int max = 0;
  for (int i = 0; i < n; ++i) {
    while (top >= 0 && stack[top] >= arr[i]) {
      int tmp = (stack[top] ^ arr[i]);
      if (tmp > max) {
        max = tmp;
      }
      --top;
    }
    if (top < 0) {
      stack[++top] = arr[i];
    } else {
      int tmp = (stack[top] ^ arr[i]);
      if (tmp > max) {
        max = tmp;
      }
      stack[++top] = arr[i];
    }
  }

  printf("%d\n", max);

  return 0;
}

