/*
 * Challenges: https://www.hackerrank.com/challenges/castle-on-the-grid/problem
 */

#include <stdio.h>
#include <memory.h>

struct Point {
  int x;
  int y;
};

struct Point dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char maze[100][101];
int  step[100][100];
int  n = 0;

struct Point queue[10000];
int head = 0;
int tail = 0;

struct Point move(const struct Point& curr, const struct Point& dir) {
  struct Point res;
  res.x = curr.x + dir.x;
  res.y = curr.y + dir.y;
  return res;
}

bool is_valid(const struct Point& curr) {
  return (curr.x >= 0) && (curr.y) >= 0 && (curr.x < n) && (curr.y < n) && ('.' == maze[curr.x][curr.y]);
}

int main () {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", maze[i]);
  }

  struct Point start;
  struct Point end;

  scanf("%d %d %d %d", &(start.x), &(start.y), &(end.x), &(end.y));
  memset(step, 0, sizeof(step));
  step[start.x][start.y] = 1;
  queue[tail++] = start;
  while (head < tail && step[end.x][end.y] == 0) {
    struct Point& curr = queue[head++];
    for (int i = 0; i < 4; ++i) {
      struct Point next;
      for(next = curr; is_valid(next); next = move(next, dir[i])) {
        if (step[next.x][next.y] == 0) {
          step[next.x][next.y] = step[curr.x][curr.y] + 1;
          queue[tail++] = next;
        }
      }
    }
  }
  printf("%d\n", step[end.x][end.y] - 1);

  return 0;
}

