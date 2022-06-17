/*
 * Challegnes: https://www.hackerrank.com/challenges/grading/problem
 */
#include <stdio.h>

int main () {
  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int grade;
    scanf("%d", &grade);
    if (grade >= 38 && grade % 5 > 2) {
      grade = (grade / 5 + 1) * 5;
    }
    printf("%d\n", grade);
  }
  return 0;
}

