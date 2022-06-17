/*
 * Challenges: https://www.hackerrank.com/challenges/jim-and-the-skyscrapers/problem
 */

#include <stdio.h>
#include <algorithm>
#include <vector>

class IntervalTree {
 public:
  IntervalTree(const int left_bound, const int right_bound) :
    root_(left_bound, right_bound),
    buffer_() {
  }
  ~IntervalTree() {
    for (int i = 0; i < buffer_.size(); ++i) {
      delete(buffer_[i]);
    }
  }

  void insert(const int left_bound, const int right_bound) {
    root_.insert(left_bound, right_bound, this);
  }
  void insert_max(const int left_bound, const int right_bound, const long value) {
    root_.insert_max(left_bound, right_bound, value, this);
  }
  long count(const int left_bound, const int right_bound) {
    return root_.count(left_bound, right_bound);
  }
  long find_max(const int left_bound, const int right_bound) {
    return root_.find_max(left_bound, right_bound);
  }
  void print_nodes() {
    root_.print();
    for (int i = 0; i < buffer_.size(); ++i) {
      buffer_[i]->print();
    }
  }

 private:
  class Node {
   public:
    Node(const int left_bound, const int right_bound) :
      left_bound_(left_bound),
      right_bound_(right_bound),
      count_(0),
      value_(0),
      lc_(NULL),
      rc_(NULL) {
    }
    ~Node() {
    }

    void insert(const int left_bound, const int right_bound, IntervalTree *interval_tree) {
      do {
        if (left_bound > right_bound_ || right_bound < left_bound_) {
          break;
        } else if (left_bound <= left_bound_ && right_bound >= right_bound_) {
          ++count_;
          break;
        }

        if (NULL == lc_) {
          lc_ = interval_tree->get_new_node(left_bound_, (left_bound_ + right_bound_) / 2);
        }
        if (NULL == rc_) {
          rc_ = interval_tree->get_new_node((left_bound_ + right_bound_) / 2 + 1, right_bound_);
        }
        lc_->insert(left_bound, right_bound, interval_tree);
        rc_->insert(left_bound, right_bound, interval_tree);
        long tmp = std::min(lc_->count(), rc_->count());
        count_ += tmp;
        lc_->decrease_count(tmp);
        rc_->decrease_count(tmp);
      } while (0);
      return;
    }
    void insert_max(const int left_bound, const int right_bound, const long value, IntervalTree *interval_tree) {
      do {
        if (left_bound > right_bound_ || right_bound < left_bound_) {
          break;
        } else if (left_bound <= left_bound_ && right_bound >= right_bound_) {
          if (value > value_) {
            value_ = value;
          }
          break;
        }

        if (NULL == lc_) {
          lc_ = interval_tree->get_new_node(left_bound_, (left_bound_ + right_bound_) / 2);
        }
        if (NULL == rc_) {
          rc_ = interval_tree->get_new_node((left_bound_ + right_bound_) / 2 + 1, right_bound_);
        }
        lc_->insert_max(left_bound, right_bound, value, interval_tree);
        rc_->insert_max(left_bound, right_bound, value, interval_tree);
        value_ = std::max(lc_->value(), rc_->value());
      } while (0);
      return;
    }
    long count(const int left_bound, const int right_bound) {
      long res = 0;
      do {
        if (left_bound > right_bound_ || right_bound < left_bound_) {
          res = 0;
          break;
        } else if (left_bound <= left_bound_ && right_bound >= right_bound_) {
          res = count_;
          break;
        }

        int middle = (left_bound_ + right_bound_) / 2;
        long l_count = 0;
        long r_count = 0;
        if (NULL != lc_) {
          l_count = lc_->count(left_bound, right_bound);
        }
        if (NULL != rc_) {
          r_count = rc_->count(left_bound, right_bound);
        }
        if (left_bound > middle) {
          res = count_ + r_count;
          break;
        } else if (right_bound <= middle) {
          res = count_ + l_count;
          break;
        }
        res = count_ + std::min(l_count, r_count);
      } while (0);
      return res;
    }
    long find_max(const int left_bound, const int right_bound) {
      long res = 0;
      do {
        if (left_bound > right_bound_ || right_bound < left_bound_) {
          res = 0;
          break;
        } else if (left_bound <= left_bound_ && right_bound >= right_bound_) {
          res = value_;
          break;
        }

        int middle = (left_bound_ + right_bound_) / 2;
        long l_max = 0;
        long r_max = 0;
        if (NULL != lc_) {
          l_max = lc_->find_max(left_bound, right_bound);
        }
        if (NULL != rc_) {
          r_max = rc_->find_max(left_bound, right_bound);
        }
        if (left_bound > middle) {
          res = r_max;
          break;
        } else if (right_bound <= middle) {
          res = l_max;
          break;
        }
        res = std::max(l_max, r_max);
      } while (0);
      return res;
    }
    long count() const {
      return count_;
    }
    long value() const {
      return value_;
    }
    void decrease_count(long value) {
      count_ -= value;
    }
    void print() const {
      printf("[%d, %d]: %ld\n", left_bound_, right_bound_, count_);
    }

   private:
    int left_bound_;
    int right_bound_;
    long count_;
    long value_;
    Node *lc_;
    Node *rc_;
  };

  Node *get_new_node(const int left_bound, const int right_bound) {
    buffer_.push_back(new Node(left_bound, right_bound));
    return buffer_.back();
  }

  Node root_;
  std::vector<Node *> buffer_;
};

std::vector<int> stack[1000001];

int main () {
  int n = 0;
  long ans = 0;

  scanf("%d", &n);
  IntervalTree interval_tree(0, n - 1);
  for (int i = 0; i < n; ++i) {
    int h;
    scanf("%d", &h);
    if (!stack[h].empty()) {
      long max = interval_tree.find_max(stack[h].back(), i - 1);
      if (max > h) {
        stack[h].clear();
      } else {
        ans += stack[h].size();
      }
    }
    interval_tree.insert_max(i, i, h);
    stack[h].push_back(i);
  }

  printf("%ld\n", ans * 2);
  return 0;
}

