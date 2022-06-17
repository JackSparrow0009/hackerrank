/*
 * Challenges: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
  static int h[26];
  static char word[16];

  for (int i = 0; i < 26; ++i) {
    scanf("%d", &h[i]);
  }

  scanf("%s", word);

  int max_height = 0;
  for (int i = 0; word[i]; ++i) {
    if (h[word[i] - 'a'] > max_height) {
      max_height = h[word[i] - 'a'];
    }
  }

  printf("%d\n", max_height * strlen(word));
  return 0;
}

