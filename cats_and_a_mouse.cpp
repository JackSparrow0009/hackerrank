/*
 * Challenges: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
 */
#include <stdio.h>

int main () {
  int q;

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    int dist_1 = x > z ? x - z : z - x;
    int dist_2 = y > z ? y - z : z - y;

    if (dist_1 == dist_2) {
      printf("Mouse C\n");
    } else if (dist_1 < dist_2) {
      printf("Cat A\n");
    } else {
      printf("Cat B\n");
    }
  }

  return 0;
}
