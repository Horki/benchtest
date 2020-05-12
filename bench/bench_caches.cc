#include <benchmark/benchmark.h>

#include "caches.hh"

using namespace CacheReplacement;

static void bench_get_opt(benchmark::State& s) {
  LRUCache<int, int> lruCache(2);
  lruCache.set(1, 1);
  while (s.KeepRunning()) {
    lruCache.get_opt(1);
  }
}
BENCHMARK(bench_get_opt);

static void bench_get(benchmark::State& s) {
  LRUCache<int, int> lruCache(2);
  lruCache.set(1, 1);
  while (s.KeepRunning()) {
    lruCache.get(1);
  }
}
BENCHMARK(bench_get);

BENCHMARK_MAIN();
