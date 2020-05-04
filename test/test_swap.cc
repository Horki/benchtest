#include <gtest/gtest.h>

#include <vector>

#include "fac.hh"
#include "swaps.hh"

TEST(SWAP_Test, test_simple_swap) {
  int a = 10;
  int b = 4;
  Swap::simple_swap(a, b);
  ASSERT_EQ(a, 4);
  ASSERT_EQ(b, 10);
}

TEST(SWAP_Test, test_simple_swap_vec) {
  std::size_t a_len = 1000;
  std::size_t b_len = 20;
  std::vector<int> a(a_len, 10);
  std::vector<int> b(b_len, 4);

  Swap::simple_swap(a, b);
  ASSERT_EQ(a[0], 4);
  ASSERT_EQ(b[0], 10);
  ASSERT_EQ(a.size(), b_len);
  ASSERT_EQ(b.size(), a_len);
}

// TODO: fix redundant tests
TEST(SWAP_Test, test_better_swap) {
  int a = 10;
  int b = 4;
  Swap::better_swap(a, b);
  ASSERT_EQ(a, 4);
  ASSERT_EQ(b, 10);
}

// TODO: fix redundant tests
TEST(SWAP_Test, test_better_swap_vec) {
  std::size_t a_len = 1000;
  std::size_t b_len = 20;
  std::vector<int> a(a_len, 10);
  std::vector<int> b(b_len, 4);

  Swap::better_swap(a, b);
  ASSERT_EQ(a[0], 4);
  ASSERT_EQ(b[0], 10);
  ASSERT_EQ(a.size(), b_len);
  ASSERT_EQ(b.size(), a_len);
}

TEST(FAC_test, test_fac) {
  ASSERT_EQ(Factorial::fac_loop(7), 5040);
  ASSERT_EQ(Factorial::fac_const(7), 5040);
  ASSERT_EQ(Factorial::fac_inline(7), 5040);
  ASSERT_EQ(Factorial::fac_regular(7), 5040);
}