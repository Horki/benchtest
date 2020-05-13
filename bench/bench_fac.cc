#include <benchmark/benchmark.h>

#include "fac.hh"

using namespace Factorial;

static void bench_fac_const(benchmark::State &s) {
  while (s.KeepRunning()) {
    fac_const(200);
  }
}
BENCHMARK(bench_fac_const);

static void bench_fac_inline(benchmark::State &s) {
  while (s.KeepRunning()) {
    fac_inline(2000);
  }
}
BENCHMARK(bench_fac_inline);

static void bench_fac_regular(benchmark::State &s) {
  while (s.KeepRunning()) {
    fac_regular(2000);
  }
}
BENCHMARK(bench_fac_regular);

static void bench_fac_loop(benchmark::State &s) {
  while (s.KeepRunning()) {
    fac_loop(2000);
  }
}
BENCHMARK(bench_fac_loop);

BENCHMARK_MAIN();
