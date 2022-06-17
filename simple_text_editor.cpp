/*
 * Challenges: https://www.hackerrank.com/challenges/simple-text-editor/problem
 */

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

vector<int> cmd;
vector<int> cmd_1;
vector<string> cmd_2;

char buffer[1000001];
int buffer_len = 0;

char input[1000001];
int input_len = 0;

int main () {
  int q = 0;

  scanf("%d", &q);
  for (int cas = 0; cas < q; ++cas) {
    int query = 0;
    int k = 0;

    scanf("%d", &query);
    switch (query) {
     case 1:
      scanf("%s", &input);
      input_len = strlen(input);

      memcpy(&(buffer[buffer_len]), input, input_len);
      buffer_len += input_len;

      cmd.push_back(query);
      cmd_1.push_back(input_len);

      buffer[buffer_len] = 0;
      break;
     case 2:
      scanf("%d", &k);
      buffer_len -= k;
      cmd.push_back(query);
      cmd_2.push_back(&(buffer[buffer_len]));

      buffer[buffer_len] = 0;
      break;
     case 3:
      scanf("%d", &k);
      printf("%c\n", buffer[k - 1]);
      break;
     case 4:
      if (cmd.size() > 0) {
        query = cmd.back();
        switch (query) {
         case 1:
          k = cmd_1.back();
          buffer_len -= k;
          cmd_1.pop_back();

          buffer[buffer_len] = 0;
          break;
         case 2:
          memcpy(&(buffer[buffer_len]), cmd_2.back().c_str(), cmd_2.back().length());
          buffer_len += cmd_2.back().length();
          cmd_2.pop_back();

          buffer[buffer_len] = 0;
          break;
         default:
          printf("unknown command: %d\n", query);
        }
        cmd.pop_back();
      }
      break;
     default:
      printf("unknown command: %d\n", query);
    }
  }

  return 0;
}

