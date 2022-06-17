/*
 * Challenges: https://www.hackerrank.com/challenges/day-of-the-programmer/problem
 */
#include <stdio.h>

int main () {
  int year;
  scanf("%d", &year);

  if (year >= 1919) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
      printf("12.09.%04d\n", year);
    } else {
      printf("13.09.%04d\n", year);
    }
  } else if (year <= 1917) {
    if (year % 4 == 0) {
      printf("12.09.%04d\n", year);
    } else {
      printf("13.09.%04d\n", year);
    }
  } else {
    printf("26.09.%04d\n", year);
  }

  return 0;
}

