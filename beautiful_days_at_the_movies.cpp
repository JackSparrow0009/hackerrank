/*
 * Challenges: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
 */
#include <stdio.h>
#include <stdlib.h>

int main () {
  int i, j, k;

  scanf("%d %d %d", &i, &j, &k);

  int total = 0;
  for (int day = i; day <= j; ++day) {
    int day_ = 0;
    for (int tmp = day; tmp; tmp /= 10) {
      day_ = day_ * 10 + tmp % 10;
    }

    if (abs(day - day_) % k == 0) {
      ++total;
    }
  }
  printf("%d\n", total);

  return 0;
}

