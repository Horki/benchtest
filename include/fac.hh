#ifndef FAC_HH_
#define FAC_HH_

namespace Factorial {
constexpr int fac_const(int n) { return (n > 1) ? n * fac_const(n - 1) : 1; }

inline int fac_inline(int n) { return (n > 1) ? n * fac_inline(n - 1) : 1; }

int fac_regular(int n) { return (n > 1) ? n * fac_regular(n - 1) : 1; }

int fac_loop(int n) {
  int r = 1;
  for (int i = 1; i <= n; ++i) {
    r *= i;
  }
  return r;
}
}  // namespace Factorial

#endif