/*
 * Challenges: https://www.hackerrank.com/challenges/balanced-brackets/problem
 */

#include <stdio.h>

char input[1001];
char stack[1001];
int top;

int main () {
  int n = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", input);

    bool match = true;
    top = -1;
    for (int j = 0; input[j]; ++j) {
      if (input[j] == '{' || input[j] == '[' || input[j] == '(') {
        stack[++top] = input[j];
      } else if (input[j] == '}') {
        if (top < 0 || stack[top] != '{') {
          match = false;
          break;
        }
        --top;
      } else if (input[j] == ']') {
        if (top < 0 || stack[top] != '[') {
          match = false;
          break;
        }
        --top;
      } else if (input[j] == ')') {
        if (top < 0 || stack[top] != '(') {
          match = false;
          break;
        }
        --top;
      } else {
        match = false;
        break;
      }
    }

    printf("%s\n", (match && top < 0) ? ("YES") : ("NO"));
  }

  return 0;
}

