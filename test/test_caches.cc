#include <gtest/gtest.h>

#include <optional>

#include "caches.hh"

using namespace CacheReplacement;

TEST(CACHE, test_get_by_same_key) {
  LRUCache<int, int> lruCache(2);
  lruCache.set(1, 2);
  ASSERT_EQ(lruCache.get(1), 2);
  lruCache.set(1, 22);
  ASSERT_EQ(lruCache.get(1), 22);
}

TEST(CACHE, test_no_exception) {
  LRUCache<int, int> lruCache(2);
  lruCache.set(1, 1);
  lruCache.set(2, 2);
  lruCache.set(3, 3);
  ASSERT_EQ(lruCache.get_opt(1), std::nullopt);
  ASSERT_EQ(lruCache.get_opt(3), std::optional<int>(3));
}

TEST(CACHE, test_out_of_range_error) {
  LRUCache<int, int> lruCache(2);
  EXPECT_THROW(
      {
        try {
          lruCache.set(1, 2);
          lruCache.set(2, 3);
          lruCache.set(3, 4);
          lruCache.get(1);  // throws an exception
        } catch (const std::range_error& e) {
          EXPECT_STREQ(e.what(), "LRU Cache: Out of Range");
          throw;
        } catch (...) {
          throw;
        }
      },
      std::range_error);
}

TEST(CACHE, test_leetcode) {
  LRUCache<int, int> lruCache(2);
  lruCache.set(1, 1);
  lruCache.set(2, 2);
  ASSERT_EQ(lruCache.get(1), 1);
  lruCache.set(3, 3);  // evicts key 2
  ASSERT_EQ(lruCache.get_opt(2), std::nullopt);
  lruCache.set(4, 4);  // evicts key 1
  ASSERT_EQ(lruCache.get_opt(1), std::nullopt);
  ASSERT_EQ(lruCache.get(3), 3);
  ASSERT_EQ(lruCache.get(4), 4);
}