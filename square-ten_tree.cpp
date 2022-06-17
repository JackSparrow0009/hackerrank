/*
 * Challenges: https://www.hackerrank.com/challenges/square-ten-tree/problem
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>

class BigNumber {
 public:
  BigNumber() :
    data_(),
    sign_(1) {
  }
  ~BigNumber() {
  }
  BigNumber(const BigNumber& other) {
    data_ = other.data();
    sign_ = other.sign();
  }
  BigNumber(BigNumber&& other) {
    data_.swap(other.data());
    sign_ = other.sign();
  }

  inline const std::vector<char>& data() const {
    return data_;
  }
  inline std::vector<char>& data() {
    return data_;
  }
  inline char sign() const {
    return sign_;
  }
  inline size_t length() const {
    return data_.size();
  }
  inline char& operator[](int index) {
    return data_[index];
  }
  inline const char& operator[](int index) const {
    return data_[index];
  }

  void set_data(const char *value) {
    int len = strlen(value);
    data_.clear();
    data_.reserve(len);
    if (value[0] == '-') {
      for (int i = strlen(value) - 1; i > 0; --i) {
        data_.push_back(value[i] - '0');
      }
      sign_ = -1;
    } else {
      for (int i = strlen(value) - 1; i >= 0; --i) {
        data_.push_back(value[i] - '0');
      }
      sign_ = 1;
    }
  }
  void set_data(long long value) {
    data_.clear();
    if (value < 0) {
      value = -value;
      sign_ = -1;
    } else {
      sign_ = 1;
    }
    for (int i = 0; value > 0; ++i) {
      data_.push_back(value % 10);
      value /= 10;
    }
  }
  void set_data(char highest, size_t power_of_ten) {
    data_.resize(power_of_ten + 1);
    memset(&(data_[0]), 0, sizeof(data_[0]) * power_of_ten);
    data_[data_.size() - 1] = highest;
    sign_ = 1;
  }
  void set_data(const std::vector<char>& highest, const std::vector<size_t>& power_of_ten) {
    size_t max = 0;
    for (size_t i = 0; i < power_of_ten.size(); ++i) {
      if (power_of_ten[i] > max) {
        max = power_of_ten[i];
      }
    }
    data_.resize(max + 1);
    memset(&(data_[0]), 0, sizeof(data_[0]) * data_.size());

    for (size_t i = 0; i < power_of_ten.size(); ++i) {
      data_[power_of_ten[i]] += highest[i];
    }
    normalize();
  }

  void operator=(const BigNumber& other) {
    data_ = other.data();
    sign_ = other.sign();
  }

  bool operator<(const BigNumber& other) const {
    if (sign_ < other.sign()) {
      return true;
    } else if (sign_ > other.sign()) {
      return false;
    } else if (((int)sign_ * (int)data_.size()) < ((int)other.sign() * (int)other.length())) {
      return true;
    } else if (((int)sign_ * (int)data_.size()) > ((int)other.sign() * (int)other.length())) {
      return false;
    }
    for (int i = (int)(data_.size() - 1); i >= 0; --i) {
      if (data_[i] < other[i]) {
        return true;
      } else if (data_[i] > other[i]) {
        return false;
      }
    }
    return false;
  }

  bool operator<=(const BigNumber& other) const {
    if (sign_ < other.sign()) {
      return true;
    } else if (sign_ > other.sign()) {
      return false;
    } else if (((int)sign_ * (int)data_.size()) < ((int)other.sign() * (int)other.length())) {
      return true;
    } else if (((int)sign_ * (int)data_.size()) > ((int)other.sign() * (int)other.length())) {
      return false;
    }
    for (int i = (int)(data_.size() - 1); i >= 0; --i) {
      if (data_[i] < other[i]) {
        return true;
      } else if (data_[i] > other[i]) {
        return false;
      }
    }
    return true;
  }

  bool operator>(const BigNumber& other) const {
    if (sign_ > other.sign()) {
      return true;
    } else if (sign_ < other.sign()) {
      return false;
    } else if (((int)sign_ * (int)data_.size()) > ((int)other.sign() * (int)other.length())) {
      return true;
    } else if (((int)sign_ * (int)data_.size()) < ((int)other.sign() * (int)other.length())) {
      return false;
    }
    for (int i = (int)(data_.size() - 1); i >= 0; --i) {
      if (data_[i] > other[i]) {
        return true;
      } else if (data_[i] < other[i]) {
        return false;
      }
    }
    return false;
  }

  bool operator>=(const BigNumber& other) const {
    if (sign_ > other.sign()) {
      return true;
    } else if (sign_ < other.sign()) {
      return false;
    } else if (((int)sign_ * (int)data_.size()) > ((int)other.sign() * (int)other.length())) {
      return true;
    } else if (((int)sign_ * (int)data_.size()) < ((int)other.sign() * (int)other.length())) {
      return false;
    }
    for (int i = (int)(data_.size() - 1); i >= 0; --i) {
      if (data_[i] > other[i]) {
        return true;
      } else if (data_[i] < other[i]) {
        return false;
      }
    }
    return true;
  }

  bool operator==(const BigNumber& other) const {
    if (sign_ != other.sign()) {
      return false;
    } else if (data_.size() != other.length()) {
      return false;
    }
    for (int i = (int)(data_.size() - 1); i >= 0; --i) {
      if (data_[i] != other[i]) {
        return false;
      }
    }
    return true;
  }

  BigNumber operator-(const BigNumber& other) const {
    BigNumber c;
    c.data().reserve(std::max(data_.size(), other.length()) + 1);
    size_t i = 0;
    for (i = 0; i < data_.size() && i < other.length(); ++i) {
      c.data().push_back(sign_ * data_[i] - other.sign() * other[i]);
    }
    for (; i < data_.size(); ++i) {
      c.data().push_back(sign_ * data_[i]);
    }
    for (; i < other.length(); ++i) {
      c.data().push_back(-other.sign() * other[i]);
    }
    c.normalize();
    return c;
  }

  BigNumber operator+(const BigNumber& other) {
    BigNumber c;
    c.data().reserve(std::max(data_.size(), other.length()) + 1);
    size_t i = 0;
    for (i = 0; i < data_.size() && i < other.length(); ++i) {
      c.data().push_back(sign_ * data_[i] + other.sign() * other[i]);
    }
    for (; i < data_.size(); ++i) {
      c.data().push_back(sign_ * data_[i]);
    }
    for (; i < other.length(); ++i) {
      c.data().push_back(other.sign_ * other[i]);
    }
    c.normalize();
    return c;
  }

  void operator+=(const BigNumber& other) {
    size_t i = 0;
    for (i = 0; i < data_.size() && i < other.length(); ++i) {
      data_[i] = (sign_ * data_[i] + other.sign() * other[i]);
    }
    for (; i < data_.size(); ++i) {
      data_[i] = sign_ * data_[i];
    }
    for (; i < other.length(); ++i) {
      data_.push_back(other.sign_ * other[i]);
    }
    this->normalize();
    return;
  }

  void operator-=(const BigNumber& other) {
    size_t i = 0;
    for (i = 0; i < data_.size() && i < other.length(); ++i) {
      data_[i] = (sign_ * data_[i] - other.sign() * other[i]);
    }
    for (; i < data_.size(); ++i) {
      data_[i] = sign_ * data_[i];
    }
    for (; i < other.length(); ++i) {
      data_.push_back(-other.sign_ * other[i]);
    }
    this->normalize();
    return;
  }

  void normalize() {
    for (; (!data_.empty()) && data_.back() == 0; data_.pop_back()) {}

    char carry = 0;
    for (size_t i = 0; i < data_.size(); ++i) {
      char temp = data_[i] + carry;
      if (temp >= 0) {
        data_[i] = temp % 10;
        carry = temp / 10;
      } else {
        carry = 0;
        for (carry = 0; temp < 0; --carry) {
          temp += 10;
        }
        data_[i] = temp;
      }
    }
    while (carry < -9 || carry > 9) {
      char temp = carry;
      if (temp >= 0) {
        data_.push_back(temp % 10);
        carry = temp / 10;
      } else {
        carry = 0;
        for (carry = 0; temp < 0; --carry) {
          temp += 10;
        }
        data_.push_back(temp);
      }
    }
    if (carry != 0) {
      data_.push_back(carry);
    }

    // deal with negative number
    if (data_.empty()) {
      sign_ = 1;
      return;
    }
    sign_ = (data_.back() < 0) ? (-1) : (1);
    if (sign_ > 0) {
      return;
    }

    carry = 0;
    for (size_t i = 0; i < data_.size(); ++i) {
      char temp = sign_ * data_[i] + carry;
      if (temp >= 0) {
        data_[i] = temp % 10;
        carry = temp / 10;
      } else {
        carry = 0;
        for (carry = 0; temp < 0; --carry) {
          temp += 10;
        }
        data_[i] = temp;
      }
    }
    for (; (!data_.empty()) && data_.back() == 0; data_.pop_back()) {}
    return;
  }

  std::string to_string() const {
    std::string res;
    if (data_.empty()) {
      res.push_back('0');
    } else {
      res.reserve(data_.size() + 1);
      if (sign_ == -1) {
        res.push_back('-');
      }
      for (int i = data_.size() - 1; i >= 0; --i) {
        res.push_back('0' + data_[i]);
      }
    }
    return res;
  }

 private:
  std::vector<char> data_;
  char sign_;
};

int main () {
  BigNumber a;
  BigNumber b;

  static char buffer[1000001];
  scanf("%s", buffer);
  a.set_data(buffer);
  scanf("%s", buffer);
  b.set_data(buffer);

  if (a < b) {
    std::vector<size_t> log2;
    for (size_t i = 0, j = 0; i < 10000001; ++i) {
      for (; (i >> j) > 0; ++j) {}
      log2.push_back(j);
    }
    BigNumber one;
    one.set_data(1);
    BigNumber c = b - a + one;

    BigNumber aa, bb, cc;
    aa.data().reserve(std::min(c.length() - 1, a.length()));
    bb.data().reserve(std::min(c.length() - 1, b.length()));
    cc.set_data(1, c.length() - 1);
    for (size_t i = 0; i + 1 < c.length(); ++i) {
      if (i < a.length()) {
        aa.data().push_back(a[i]);
      }
      if (i < b.length()) {
        bb.data().push_back(b[i]);
      }
    }

    aa = cc - aa + one;
    std::vector<size_t> level;
    std::vector<char> count;
    std::vector<int> power;
    if (c.length() > 1) {
      for (size_t i = 0; i < aa.length(); ++i) {
        if (aa[i] > 0) {
          level.push_back(log2[i]);
          count.push_back(aa[i]);
          power.push_back((i > 0) ? (i - (1 << (log2[i] - 1))) : (0));
        }
      }
    }

    BigNumber dd = c - aa - bb;
    level.push_back(log2[c.length() - 1]);
    count.push_back(dd.data().back());
    power.push_back((c.length() - 1 > 0) ? (c.length() - 1 - (1 << (log2[c.length() - 1] - 1))) : (0));

    if (c.length() > 1) {
      for (int i = bb.length() - 1; i >= 0; --i) {
        if (bb[i] > 0) {
          level.push_back(log2[i]);
          count.push_back(bb[i]);
          power.push_back((i > 0) ? (i - (1 << (log2[i] - 1))) : (0));
        }
      }
    }

    std::vector<size_t> level_ans;
    std::vector<std::vector<char> > count_ans;
    std::vector<std::vector<size_t> >  power_ans;
    for (size_t i = 0; i < level.size(); ++i) {
      if (level_ans.empty() || level_ans.back() != level[i]) {
        level_ans.push_back(level[i]);
        count_ans.emplace_back();
        power_ans.emplace_back();
        count_ans.back().push_back(count[i]);
        power_ans.back().push_back((size_t)power[i]);
      } else {
        count_ans.back().push_back(count[i]);
        power_ans.back().push_back((size_t)power[i]);
      }
    }

    printf("%d\n", (int)(level_ans.size()));
    for (size_t i = 0; i < level_ans.size(); ++i) {
      printf("%d ", (int)(level_ans[i]));
      BigNumber temp;
      temp.set_data(count_ans[i], power_ans[i]);
      printf("%s\n", temp.to_string().c_str());
    }
  } else if (a == b) {
    printf("1\n0 1\n");
  }
  return 0;
}

