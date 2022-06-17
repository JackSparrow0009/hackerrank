/*
 * Challenges: https://www.hackerrank.com/challenges/dynamic-array/problem
 */
#include <stdio.h>
#include <vector>

using std::vector;

int main() {
  int n, q;
  int last_answer = 0;
  vector<vector<int>> seq_list;

  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    vector<int> tmp;
    seq_list.push_back(tmp);
  }
  for (int i = 0; i < q; ++i) {
    int cmd, x, y;
    scanf("%d %d %d", &cmd, &x, &y);
    if (1 == cmd) {
      int seq_id = (x ^ last_answer) % n;
      seq_list[seq_id].push_back(y);
    } else if (2 == cmd) {
      int seq_id = (x ^ last_answer) % n;
      last_answer = seq_list[seq_id][y % seq_list[seq_id].size()];
      printf("%d\n", last_answer);
    }
  }
  return 0;
}

