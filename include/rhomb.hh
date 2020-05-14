#ifndef RHOMB_HH_
#define RHOMB_HH_

#include <algorithm>
#include <iterator>
#include <ostream>
#include <vector>

namespace Rhomb {
class Rhomboid {
  std::vector<std::vector<char>> matrix;

 public:
  Rhomboid(std::size_t n) : matrix(n, std::vector<char>(2 * n - 1, ' ')) {
    for (std::size_t idx = 0; idx < n; ++idx) {
      matrix[idx][n + idx - 1] = '*';
      matrix[idx][n - idx - 1] = '*';
    }
  }
  friend std::ostream &operator<<(std::ostream &, const Rhomboid &);
};

std::ostream &operator<<(std::ostream &os, const Rhomboid &m) {
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
}  // namespace Rhomb

#endif