/*
 * Challenges: https://www.hackerrank.com/challenges/counting-valleys/problem
 */
#include <stdio.h>
#include <memory.h>

char s[1000001];

int main () {
  int n;

  scanf("%d", &n);
  scanf("%s", s);

  int state = 0;
  int cnt   = 0;
  for (int i = 0; s[i]; ++i) {
    if (state == 0 && s[i] == 'D') {
      ++cnt;
    }

    if (s[i] == 'D') {
      --state;
    } else {
      ++state;
    }
  }

  printf("%d\n", cnt);

  return 0;
}

