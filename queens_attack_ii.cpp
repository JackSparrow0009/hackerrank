/*
 * Challenges: https://www.hackerrank.com/challenges/queens-attack-2/problem
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main () {
  static int dist[8];

  int n, k;
  scanf("%d %d", &n, &k);

  int r, c;
  scanf("%d %d", &r, &c);

  dist[0] = n + 1 - r;   // up
  dist[1] = n + 1 - c;   // right
  dist[2] = r;           // down
  dist[3] = c;           // left
  dist[4] = (dist[0] < dist[1] ? dist[0] : dist[1]); // up-right
  dist[5] = (dist[2] < dist[1] ? dist[2] : dist[1]); // down-right
  dist[6] = (dist[2] < dist[3] ? dist[2] : dist[3]); // down-left
  dist[7] = (dist[0] < dist[3] ? dist[0] : dist[3]); // up-left

  for (int i = 0; i < k; ++i) {
    int _r, _c;
    scanf("%d %d", &_r, &_c);

    if (_c == c && _r > r) { // up
      dist[0] = (_r - r < dist[0] ? _r - r : dist[0]);
    }
    if (_r == r && _c > c) { // right
      dist[1] = (_c - c < dist[1] ? _c - c : dist[1]);
    }
    if (_c == c && _r < r) { // down
      dist[2] = (r - _r < dist[2] ? r - _r : dist[2]);
    }
    if (_r == r && _c < c) { // left
      dist[3] = (c - _c < dist[3] ? c - _c : dist[3]);
    }
    if (_r > r && _r - r == _c - c) { // up-right
      dist[4] = (_r - r < dist[4] ? _r - r : dist[4]);
    }
    if (_r < r && r - _r == _c - c) { // down_right
      dist[5] = (r - _r < dist[5] ? r - _r : dist[5]);
    }
    if (_r < r && r - _r == c - _c) { // down_left
      dist[6] = (r - _r < dist[6] ? r - _r : dist[6]);
    }
    if (_r > r && _r - r == c - _c) { // up-left
      dist[7] = (_r - r < dist[7] ? _r - r : dist[7]);
    }
  }

  int result = 0;
  for (int i = 0; i < 8; ++i) {
    result += dist[i] - 1;
  }

  printf("%d\n", result);

  return 0;
}

