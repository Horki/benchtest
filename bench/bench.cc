#include <benchmark/benchmark.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

#include "odd_num.hh"
#include "swaps.hh"

static void bench_init_list(benchmark::State &s) {
  while (s.KeepRunning()) {
    std::list<int> l{1};
  }
}
BENCHMARK(bench_init_list);

static void bench_init_vec(benchmark::State &s) {
  while (s.KeepRunning()) {
    std::vector<int> l{1};
  }
}
BENCHMARK(bench_init_vec);

static void bench_odd_class(benchmark::State &s) {
  std::vector<unsigned> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  while (s.KeepRunning()) {
    std::cerr.setstate(std::ios_base::failbit);
    std::for_each(v.begin(), v.end(), PrintOdd{std::cerr});
  }
}
BENCHMARK(bench_odd_class);

static void bench_odd_fn(benchmark::State &s) {
  std::vector<unsigned> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  while (s.KeepRunning()) {
    std::cerr.setstate(std::ios_base::failbit);
    print_odd(v, std::cerr);
  }
}
BENCHMARK(bench_odd_fn);

static void bench_simple_swap(benchmark::State &s) {
  std::vector<int> a(10000000, 3);
  std::vector<int> b(10000000, 2);
  for (auto _ : s) {
    simple_swap(a, b);
  }
}
BENCHMARK(bench_simple_swap);

static void bench_better_swap(benchmark::State &s) {
  std::vector<int> a(10000000, 3);
  std::vector<int> b(10000000, 2);
  for (auto _ : s) {
    better_swap(a, b);
  }
}
BENCHMARK(bench_better_swap);

static void bench_std_swap(benchmark::State &s) {
  std::vector<int> a(10000000, 3);
  std::vector<int> b(10000000, 2);
  for (auto _ : s) {
    std::swap(a, b);
  }
}
BENCHMARK(bench_std_swap);

BENCHMARK_MAIN();
