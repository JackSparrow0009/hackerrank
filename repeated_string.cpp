/*
 * Challenges: https://www.hackerrank.com/challenges/repeated-string/problem
 */
#include <stdio.h>
#include <string.h>

int main () {
  static char str[101];
  long long n;

  scanf("%s", str);
  scanf("%lld", &n);

  long long len = strlen(str);
  long long repeated = n / len;
  long long remain   = n % len;

  long long cnt_1 = 0;
  long long cnt_2 = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == 'a') {
      ++cnt_1;
      if (i < remain) {
        ++cnt_2;
      }
    }
  }

  printf("%lld\n", cnt_1 * repeated + cnt_2);

  return 0;
}

