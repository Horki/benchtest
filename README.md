# benchtest
Testing google [benchmark](https://youtu.be/nXaxk27zwlk)

## Os X

```console
Apple LLVM version 10.0.1 (clang-1001.0.46.3)
Target: x86_64-apple-darwin18.5.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

### Result
```console
Run on (8 X 2200 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 6291K (x1)
-------------------------------------------------------
Benchmark                Time           CPU Iterations
-------------------------------------------------------
bench_create             0 ns          0 ns 1000000000
bench_reserve            0 ns          0 ns 1000000000
bench_push_back          2 ns          2 ns  355207340
```

## Arch Linux

### Result
