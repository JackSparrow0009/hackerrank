/*
 * Challenges: https://www.hackerrank.com/challenges/jenny-subtrees/problem
 * Solution:   https://kmjp.hatenablog.jp/entry/2017/01/03/0930
 */

#include <stdio.h>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <algorithm>

int n = 0;
int r = 0;
std::vector<int> neighbor[5001];

std::bitset<5001> mark;
std::unordered_set<std::bitset<5001> > nodeset_set;
std::set<std::vector<long long> > iso_set;

int ctim = 0;
int tim[5001][5001];
long long memo[5001][5001];

static long long tree_hash(std::vector<long long>& tree) {
  long long momo[2]={1000000007, 1000000009};
  std::vector<long long> prim = {100291,100297,100313,100333,100343,100357,100361,100363,100379,100391};

  std::sort(tree.begin(), tree.end());
  int id1 = 0;
  int id2 = 1;
  long long a = 1;
  long long b = 1;

  for (size_t i = 0; i < tree.size(); ++i) {
    long long h = tree[i] >> 32;
    long long l = tree[i] - (h << 32);
    (a += h * prim[(id1++) % prim.size()]) %= momo[0];
    (b += l * prim[(id2++) % prim.size()]) %= momo[1];
  }

  return (a << 32) + b;
}

static void dfs1(int curr, int prev, int depth) {
  mark[curr] = 1;
  if (depth > 0) {
    for (size_t i = 0; i < neighbor[curr].size(); ++i) {
      int& v = neighbor[curr][i];
      if (v != prev && mark[v] == 0) {
        dfs1(v, curr, depth - 1);
      }
    }
  }
}

static long long dfs2(int curr, int prev) {
  if (ctim == tim[prev][curr]) {
    return memo[prev][curr];
  }

  std::vector<long long> subtree_signs;
  subtree_signs.push_back((1LL) + (1LL << 32));
  for (size_t i = 0; i < neighbor[curr].size(); ++i) {
    int& v = neighbor[curr][i];
    if (v != prev && mark[v] == 1) {
      subtree_signs.push_back(dfs2(v, curr));
    }
  }
  memo[prev][curr] = tree_hash(subtree_signs);
  tim[prev][curr] = ctim;

  return memo[prev][curr];
}

int main () {
  scanf("%d %d", &n, &r);
  for (int i = 0; i < n - 1; ++i) {
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    neighbor[x - 1].push_back(y - 1);
    neighbor[y - 1].push_back(x - 1);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      mark[j] = 0;
    }

    dfs1(i, 5000, r);
    if (nodeset_set.count(mark)) {
      continue;
    }
    nodeset_set.insert(mark);

    ctim = i + 1;
    std::vector<long long> subtree_signs;
    for (int j = 0; j < n; ++j) {
      if (mark[j] == 0) {
        continue;
      }
      subtree_signs.push_back(dfs2(j, 5000));
    }

    sort(subtree_signs.begin(), subtree_signs.end());
    iso_set.insert(subtree_signs);
  }
  printf("%d\n", (int)iso_set.size());

  return 0;
}

