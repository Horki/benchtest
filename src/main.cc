#include <algorithm>
#include <iostream>
#include <vector>

#include "odd_num.hh"

int main() {
  std::vector<unsigned> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  OddNumber::print_odd(v, std::cout);
  std::for_each(v.begin(), v.end(), OddNumber::PrintOdd(std::cout));
}
