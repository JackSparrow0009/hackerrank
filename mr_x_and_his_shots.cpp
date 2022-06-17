/*
 * Challenges: https://www.hackerrank.com/challenges/x-and-his-shots/problem
 */

#include <stdio.h>
#include <algorithm>
#include <vector>

class Point {
 public:
  Point(const int index, const int value) :
    index_(index),
    value_(value) {
  }
  ~Point() {
  }
  bool operator<(const Point& other) const {
    return (index_ < other.index()) || ((index_ == other.index()) && (value_ > other.value()));
  }
  bool operator>(const Point& other) const {
    return (index_ > other.index()) || ((index_ == other.index()) && (value_ < other.value()));
  }
  int index() const {
    return index_;
  }
  int value() const {
    return value_;
  }

 private:
  int index_;
  int value_;
};

int main () {
  int n = 0;
  int m = 0;

  std::vector<Point> points;

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    points.emplace_back(a, +1);
    points.emplace_back(b, -1);
  }

  std::sort(points.begin(), points.end());
  std::vector<int> sum_a;
  std::vector<int> sum_b;
  for (int i = 0; i < points.size(); ++i) {
    if (i > 0) {
      sum_a.push_back(sum_a.back() + points[i].value());
      sum_b.push_back(sum_b.back() + ((points[i].value() > 0) ? (1) : (0)));
    } else {
      sum_a.push_back(points[i].value());
      sum_b.push_back((points[i].value() > 0) ? (1) : (0));
    }
  }
  // for (int i = 0; i < sum_a.size(); ++i) {
  //   printf("> %d %d\n", sum_a[i], sum_b[i]);
  // }

  long ans = 0;
  for (int i = 0; i < m; ++i) {
    int c = 0;
    int d = 0;
    scanf("%d %d", &c, &d);

    int begin  = -1;
    int length = (1 << 20);
    for (; length; length >>= 1) {
      if (begin + length < points.size() && points[begin + length].index() < c) {
        begin += length;
      }
    }
    int count_1a = (begin >= 0) ? (sum_a[begin]) : (0);
    int count_1b = (begin >= 0) ? (sum_b[begin]) : (0);

    begin = -1;
    length = (1 << 20);
    for (; length; length >>= 1) {
      if (begin + length < points.size() && points[begin + length].index() <= d) {
        begin += length;
      }
    }
    int count_2b = (begin >= 0) ? (sum_b[begin]) : (0);

    ans += count_1a + (count_2b - count_1b);
  }

  printf("%ld\n", ans);

  return 0;
}

