#include <benchmark/benchmark.h>

#include <list>
#include <vector>

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

BENCHMARK_MAIN();
