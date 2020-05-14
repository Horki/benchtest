#ifndef RHOMB_HH_
#define RHOMB_HH_

#include <algorithm>
#include <iterator>
#include <ostream>
#include <vector>

namespace Rhomb {
class RhomboidMatrix {
  std::vector<std::vector<char>> matrix;

 public:
  RhomboidMatrix(std::size_t n) : matrix(n, std::vector<char>(2 * n - 1, ' ')) {
    for (std::size_t idx = 0; idx < n; ++idx) {
      matrix[idx][n + idx - 1] = '*';
      matrix[idx][n - idx - 1] = '*';
    }
  }
  friend std::ostream &operator<<(std::ostream &, const RhomboidMatrix &);
};

std::ostream &operator<<(std::ostream &os, const RhomboidMatrix &m) {
  for (const auto &row : m.matrix) {
    std::copy(row.begin(), row.end(), std::ostream_iterator<char>(os, ""));
    os << "\n";
  }
  for (auto r_iter = m.matrix.rbegin() + 1; r_iter != m.matrix.rend();
       r_iter++) {
    std::copy(r_iter->begin(), r_iter->end(),
              std::ostream_iterator<char>(os, ""));
    os << "\n";
  }
  return os;
}

class Rhomboid {
  std::size_t n;

 public:
  Rhomboid(std::size_t n) : n(n) {}
  friend std::ostream &operator<<(std::ostream &, const Rhomboid &);
};

std::ostream &operator<<(std::ostream &os, const Rhomboid &m) {
  for (std::size_t i = 0; i < m.n; ++i) {
    // row
    for (std::size_t j = 0; j < (m.n * 2 - 1); ++j) {
      if ((m.n + i - 1) == j || (m.n - i - 1) == j) {
        os << '*';
      } else {
        os << ' ';
      }
    }
    os << '\n';
  }
  for (int i = m.n - 2; i >= 0; --i) {
    // row
    for (std::size_t j = 0; j <= (m.n * 2); ++j) {
      if ((m.n + i - 1) == j || (m.n - i - 1) == j) {
        os << '*';
      } else {
        os << ' ';
      }
    }
    os << '\n';
  }

  return os;
}

}  // namespace Rhomb

#endif