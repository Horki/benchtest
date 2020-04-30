#ifndef SWAPS_HH_
#define SWAPS_HH_

#include <memory>

template <typename T>
void simple_swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
void better_swap(T& a, T& b) {
  T tmp{std::move(a)};
  a = std::move(b);
  b = std::move(tmp);
}

#endif
