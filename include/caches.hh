#ifndef CACHES_HH_
#define CACHES_HH_

#include <iterator>
#include <list>
#include <optional>
#include <unordered_map>

namespace CacheReplacement {

template <typename K, typename V>
class CacheReplacement {
 public:
  // Time Average: O(1)
  virtual const V& get(const K&) = 0;
  virtual std::optional<std::reference_wrapper<const V>> get_opt(
      const K&) noexcept = 0;
  // Time Average: O(1)
  virtual void set(const K&, const V&) = 0;
  virtual ~CacheReplacement() = default;
};

template <typename K, typename V>
class LRUCache : public CacheReplacement<K, V> {
  using LinkedList = std::list<std::pair<K, V>>;
  LinkedList linkedList;
  std::unordered_map<K, typename LinkedList::iterator> hash;
  const std::size_t capacity;

 public:
  explicit LRUCache(std::size_t capacity) : capacity(capacity) {}
  void set(const K& key, const V& val) {
    auto it = hash.find(key);
    linkedList.push_front(std::pair<K, V>(key, val));
    if (it != hash.end()) {
      linkedList.erase(it->second);
      hash.erase(it);
    }
    hash[key] = linkedList.begin();

    if (hash.size() > capacity) {
      auto last = linkedList.end();
      --last;
      hash.erase(last->first);
      linkedList.pop_back();
    }
  }

  const V& get(const K& key) {
    auto iterator = hash.find(key);
    if (iterator == hash.end()) {
      throw std::range_error("LRU Cache: Out of Range");
    }
    // Last used is set to begging of doubly linked list.
    linkedList.begin() = iterator->second;
    return linkedList.begin()->second;
  }

  // Avoid exceptions
  std::optional<std::reference_wrapper<const V>> get_opt(
      const K& key) noexcept {
// SLOW!!!
//    try {
//      return get(key);
//    } catch (const std::range_error&) {
//      return std::nullopt;
//    }
    auto iterator = hash.find(key);
    if (iterator == hash.end()) {
      return std::nullopt;
    }
    // Last used is set to begging of doubly linked list.
    linkedList.begin() = iterator->second;
    return linkedList.begin()->second;

  }

  const LinkedList& getList() { return linkedList; }
};
}  // namespace CacheReplacement
#endif