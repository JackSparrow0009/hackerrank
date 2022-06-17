/*
 * Challenges: https://www.hackerrank.com/challenges/save-the-prisoner/problem
 */
#include <stdio.h>

int main () {
  int case_num;

  scanf("%d", &case_num);
  for (int cas = 0; cas < case_num; ++cas) {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);

    m = m % n;
    int ans = (s + m - 1) % n;
    if (ans < 1) {
      ans = n;
    }
    printf("%d\n", ans);
  }
  return 0;
}

