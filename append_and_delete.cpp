/*
 * Challenges: https://www.hackerrank.com/challenges/append-and-delete/problem
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
  static char str1[128];
  static char str2[128];
  int k;

  scanf("%s", str1);
  scanf("%s", str2);
  scanf("%d", &k);

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  int ret = 0;
  do {
    if (len1 + len2 <= k) {
      ret = 1;
      break;
    }

    int prefix = 0;
    for (prefix = 0; prefix < len1 && prefix < len2 && str1[prefix] == str2[prefix]; ++prefix) {}

    int op_num = (len1 - prefix) + (len2 - prefix);
    if (op_num <= k && (k - op_num) % 2 == 0) {
      ret = 1;
      break;
    }
  } while (0);

  printf("%s\n", ret ? "Yes" : "No");

  return 0;
}
