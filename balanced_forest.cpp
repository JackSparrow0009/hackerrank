/*
 * Challenges: https://www.hackerrank.com/challenges/balanced-forest/problem
 */

#include <stdio.h>
#include <memory.h>
#include <vector>
#include <unordered_map>

class Tree {
 public:
  Tree() :
    buffer_node_(),
    buffer_edge_(),
    time_stamp_(0),
    sum_(0) {
  }
  explicit Tree(size_t num_node) :
    buffer_node_(num_node),
    buffer_edge_(num_node - 1),
    time_stamp_(0),
    sum_(0) {
  }
  ~Tree() {
  }

  void add_node(const size_t id, const long long value) {
    buffer_node_[id].set_id(id);
    buffer_node_[id].set_value(value);
  }
  void add_edge(const size_t id, const size_t x, const size_t y) {
    buffer_edge_[id].set_id(id);
    buffer_edge_[id].set_node(x, y);
    buffer_node_[x].add_edge(id);
    buffer_node_[y].add_edge(id);
  }
  void dfs() {
    buffer_node_[0].dfs(this, &time_stamp_, &sum_);
  }
  long long sum() const {
    return sum_;
  }
  long long calculate() {
    long long res = -1;

    std::unordered_map<long long, std::vector<size_t> > lut;
    for (size_t i = 0; i < buffer_edge_.size(); ++i) {
      lut[buffer_edge_[i].value()].push_back(i);
    }

    // case-1
    for (size_t i = 0; i < buffer_edge_.size(); ++i) {
      long long value = buffer_edge_[i].value();
      if (value * 3 < sum_) {
        continue;
      }
      long long tmp = value * 3 - sum_;
      if (lut[value].size() < 2) {
        continue;
      }
      if (res < 0 || tmp < res) {
        // printf("case-1: %lld %lld\n", (long long)i, tmp);
        res = tmp;
      }
    }
    // case-2
    for (size_t i = 0; i < buffer_edge_.size(); ++i) {
      long long value = buffer_edge_[i].value();
      if (value * 3 < sum_) {
        continue;
      }
      long long tmp = value * 3 - sum_;
      long long tmp2 = value - tmp;
      if (lut.find(tmp2) == lut.end()) {
        continue;
      }
      for (int j = 0; j < lut[tmp2].size(); ++j) {
        if (buffer_edge_[lut[tmp2][j]].begin() > buffer_edge_[i].end()
            || buffer_edge_[lut[tmp2][j]].end() < buffer_edge_[i].begin()) {
          if (res < 0 || tmp < res) {
            // printf("case-2: %lld %lld\n", (long long)i, tmp);
            res = tmp;
          }
        }
      }
    }
    // case-3
    for (size_t i = 0; i < buffer_edge_.size(); ++i) {
      long long value = buffer_edge_[i].value();
      if (value * 3 < sum_) {
        continue;
      }
      long long tmp = value * 3 - sum_;
      long long tmp2 = value * 2;
      if (lut.find(tmp2) == lut.end()) {
        continue;
      }
      for (int j = 0; j < lut[tmp2].size(); ++j) {
        if (buffer_edge_[lut[tmp2][j]].begin() < buffer_edge_[i].begin()
            && buffer_edge_[lut[tmp2][j]].end() > buffer_edge_[i].end()) {
          if (res < 0 || tmp < res) {
            // printf("case-3: %lld %lld\n", (long long)i, tmp);
            res = tmp;
          }
        }
      }
    }
    // case-4
    for (size_t i = 0; i < buffer_edge_.size(); ++i) {
      long long value = buffer_edge_[i].value();
      if (value * 3 < sum_) {
        continue;
      }
      long long tmp = value * 3 - sum_;
      long long tmp2 = value - tmp + value;
      if (lut.find(tmp2) == lut.end()) {
        continue;
      }
      for (int j = 0; j < lut[tmp2].size(); ++j) {
        if (buffer_edge_[lut[tmp2][j]].begin() < buffer_edge_[i].begin()
            && buffer_edge_[lut[tmp2][j]].end() > buffer_edge_[i].end()) {
          if (res < 0 || tmp < res) {
            // printf("case-4: %lld %lld\n", (long long)i, tmp);
            res = tmp;
          }
        }
      }
    }
    // case-5
    for (size_t i = 0; i < buffer_edge_.size(); ++i) {
      long long value = (sum_ - buffer_edge_[i].value()) / 2;
      if (value * 2 + buffer_edge_[i].value() != sum_) {
        continue;
      }
      if (value * 3 < sum_) {
        continue;
      }
      long long tmp = value * 3 - sum_;
      long long tmp2 = value - tmp + value;
      if (lut.find(tmp2) == lut.end()) {
        continue;
      }
      for (int j = 0; j < lut[tmp2].size(); ++j) {
        if (buffer_edge_[lut[tmp2][j]].begin() < buffer_edge_[i].begin()
            && buffer_edge_[lut[tmp2][j]].end() > buffer_edge_[i].end()) {
          if (res < 0 || tmp < res) {
            // printf("case-5: %lld %lld %lld\n", (long long)i, tmp, buffer_edge_[i].value());
            res = tmp;
          }
        }
      }
    }
    // case-6
    for (size_t i = 0; i < buffer_edge_.size(); ++i) {
      long long value = buffer_edge_[i].value();
      if (value * 2 != sum_) {
        continue;
      }
      if (res < 0 || value < res) {
        // printf("case-6: %lld %lld\n", (long long)i, value);
        res = value;
      }
    }
    return res;
  }

 private:
  class Edge;

  class Node {
   public:
    Node() :
      id_(0),
      value_(0),
      visited_(0),
      edge_() {
    }
    ~Node() {
    }

    inline char visited() const {
      return visited_;
    }
    inline long long value() const {
      return value_;
    }
    inline void set_value(const long long value) {
      value_ = value;
    }
    inline void set_id(const size_t id) {
      id_ = id;
    }
    inline void add_edge(const size_t id) {
      edge_.push_back(id);
    }

    void dfs(Tree *tree, size_t *time_stamp, long long *sum) {
      visited_ = 1;

      (*sum) += value_;
      for (size_t i = 0; i < edge_.size(); ++i) {
        size_t next = tree->buffer_edge_[edge_[i]].first();
        if (id_ == next) {
          next = tree->buffer_edge_[edge_[i]].second();
        }
        if (tree->buffer_node_[next].visited() == 0) {
          tree->buffer_edge_[edge_[i]].set_begin(++(*time_stamp));
          long long tmp = *sum;
          tree->buffer_node_[next].dfs(tree, time_stamp, sum);
          tree->buffer_edge_[edge_[i]].set_value((*sum) - tmp);
          tree->buffer_edge_[edge_[i]].set_end(++(*time_stamp));
        }
      }
    }

   private:
    size_t id_;
    long long value_;
    char visited_;
    std::vector<size_t> edge_;
  };

  class Edge {
   public:
    Edge() :
      id_(0),
      value_(0),
      begin_(0),
      end_(0),
      node_() {
    }
    ~Edge() {
    }

    inline long long value() const {
      return value_;
    }
    inline size_t first() const {
      return node_.first;
    }
    inline size_t second() const {
      return node_.second;
    }
    inline void set_value(const long long value) {
      value_ = value;
    }
    inline void set_id(const size_t id) {
      id_ = id;
    }
    inline void set_node(const size_t x, const size_t y) {
      node_.first  = x;
      node_.second = y;
    }
    inline void set_begin(const size_t time_stamp) {
      begin_ = time_stamp;
    }
    inline void set_end(const size_t time_stamp) {
      end_ = time_stamp;
    }
    inline size_t begin() const {
      return begin_;
    }
    inline size_t end() const {
      return end_;
    }

   private:
    size_t id_;
    long long value_;
    size_t begin_;
    size_t end_;
    std::pair<size_t, size_t> node_;
  };

  std::vector<Node> buffer_node_;
  std::vector<Edge> buffer_edge_;
  size_t time_stamp_;
  long long sum_;
};

int main () {
  int q = 0;
  scanf("%d", &q);

  for (int cas = 0; cas < q; ++cas) {
    int n = 0;
    scanf("%d", &n);
    Tree tree(n);

    for (int i = 0; i < n; ++i) {
      int c = 0;
      scanf("%d", &c);
      tree.add_node(i, c);
    }
    for (int i = 0; i + 1 < n; ++i) {
      int x = 0;
      int y = 0;
      scanf("%d %d", &x, &y);
      tree.add_edge(i, x - 1, y - 1);
    }

    tree.dfs();
    printf("%lld\n", tree.calculate());
  }
  return 0;
}

