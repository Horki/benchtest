#ifndef ODD_NUM_HH_
#define ODD_NUM_HH_

#include <algorithm>
#include <ostream>
#include <vector>

class PrintOdd {
  std::ostream& os;

 public:
  PrintOdd(std::ostream& os) : os(os) {}
  void operator()(unsigned i) const {
    if (i % 2 == 1) {
      os << i << ", ";
    }
  }
};

void print_odd(std::vector<unsigned>& v, std::ostream& os) {
  std::for_each(v.begin(), v.end(), [&os](unsigned i) {
    if (i % 2 == 1) {
      os << i << ", ";
    }
  });
}

#endif
