#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

#include "caches.hh"
#include "odd_num.hh"
#include "rhomb.hh"

void output_lru(const std::list<std::pair<int, int>>&);

int main() {
  std::vector<unsigned> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  OddNumber::print_odd(v, std::cout);
  std::for_each(v.begin(), v.end(), OddNumber::PrintOdd(std::cout));
  std::cout << "\n***************************************\n";
  {
    using namespace CacheReplacement;
    LRUCache<int, int> lruCache(2);
    const auto& l = lruCache.getList();
    lruCache.set(10, 2);
    output_lru(l);
    lruCache.set(1, 2);
    output_lru(l);
    lruCache.set(3, 3);
    output_lru(l);
  }
  {
    using namespace Rhomb;
    RhomboidMatrix rm(3);
    std::cout << rm;
    Rhomboid r(3);
    std::cout << r;
  }
}

void output_lru(const std::list<std::pair<int, int>>& l) {
  std::cout << "BEGIN\n";
  for (const auto& i : l) {
    std::cout << "key: " << i.first << ", value: " << i.second << "\n";
  }
  std::cout << "DONE\n";
}