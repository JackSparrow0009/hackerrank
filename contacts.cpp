/*
 * https://www.hackerrank.com/challenges/contacts/problem
 */

#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

class Trie {
 public:
  Trie() :
    buffer_(),
    root_() {
  }
  ~Trie() {
    for (int i = 0; i < buffer_.size(); ++i) {
      delete(buffer_[i]);
    }
  }

  bool empty() {
    return 0 == root_.count();
  }
  bool size() {
    return root_.count();
  }

  void insert(char *value) {
    Node *iter = &root_;
    iter->increase();
    for (int i = 0; value[i]; ++i) {
      iter = iter->insert(value[i], this);
      iter->increase();
    }
    iter = iter->insert('\0', this);
    iter->increase();
    return;
  }
  // std::vector<std::string> find(char *value) {
  // }
  size_t count(char *value) {
    Node *iter = &root_;
    for (int i = 0; value[i]; ++i) {
      iter = iter->move(value[i]);
      if (NULL == iter) {
        return 0;
      }
    }
    return iter->count();
  }
  void print_nodes () {
    for (int i = 0; i < buffer_.size(); ++i) {
      printf("%p %d\n", buffer_[i], buffer_[i]->count());
    }
  }

 private:
  class Node;
  class Edge;

  class Node {
   public:
    Node() :
      count_(0),
      son_() {
    }
    ~Node() {
    }
    inline size_t count() const {
      return count_;
    }
    void increase() {
      ++count_;
    }
    Node *insert(const char value, Trie *trie) {
      for (int i = 0; i < son_.size(); ++i) {
        if (son_[i].value() == value) {
          return son_[i].next();
        }
      }
      son_.emplace_back(value, trie->get_new_node());
      return son_.back().next();
    }
    Node *move(const char value) const {
      for (int i = 0; i < son_.size(); ++i) {
        if (son_[i].value() == value) {
          return son_[i].next();
        }
      }
      return NULL;
    }

   private:
    size_t count_;
    std::vector<Edge> son_;
  };

  class Edge {
   public:
    Edge() :
      value_('\0'),
      next_(NULL) {
    }
    explicit Edge(const char value) :
      value_(value),
      next_(NULL) {
    }
    Edge(const char value, Node *next) :
      value_(value),
      next_(next) {
    }
    ~Edge() {
    }

    inline char value() const {
      return value_;
    }
    inline Node *next() const {
      return next_;
    }
    inline void set_value(const char value) {
      value_ = value;
    }
    inline void set_next(Node *next) {
      next_ = next;
    }

   private:
    char value_;
    Node *next_;
  };

  Node *get_new_node() {
    buffer_.push_back(new Node());
    return buffer_.back();
  }

  Node root_;
  std::vector<Node *> buffer_;
};

char cmd[22];
char str[22];

int main () {
  Trie trie;

  int n = 0;
  scanf("%d", &n);
  for (int cas = 0; cas < n; ++cas) {
    scanf("%s %s", cmd, str);
    if (strcmp(cmd, "add") == 0) {
      trie.insert(str);
    } else {
      printf("%d\n", trie.count(str));
    }
  }

  return 0;
}

