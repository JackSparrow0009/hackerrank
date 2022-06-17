/*
 * Challenges: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem
 */
#include <stdio.h>

int main () {
  int n;
  int max;
  int min;
  int cnt_1 = 0;
  int cnt_2 = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int score;
    scanf("%d", &score);
    if (i == 0) {
      max = min = score;
    } else {
      if (max < score) {
        max = score;
        ++cnt_1;
      }
      if (min > score) {
        min = score;
        ++cnt_2;
      }
    }
  }

  printf("%d %d\n", cnt_1, cnt_2);
  return 0;
}

