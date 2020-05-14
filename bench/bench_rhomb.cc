#include <benchmark/benchmark.h>

#include <iostream>

#include "rhomb.hh"

using namespace Rhomb;

constexpr std::size_t TIMES = 200;

static void bench_with_vector(benchmark::State& s) {
  RhomboidMatrix rm(TIMES);
  while (s.KeepRunning()) {
    std::clog.setstate(std::ios_base::failbit);
    std::clog << rm;
  }
}
BENCHMARK(bench_with_vector);

static void bench_without_vector(benchmark::State& s) {
  Rhomboid rm(TIMES);
  while (s.KeepRunning()) {
    std::clog.setstate(std::ios_base::failbit);
    std::clog << rm;
  }
}
BENCHMARK(bench_without_vector);