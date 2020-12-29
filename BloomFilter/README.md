# Bloom Filter

Implementation of Bloom Filter using `xxHash` and cpp `bitset`.

Bloom Filters are probabalistic Data Structures, the `has` method may return false
positives, but will not return false negatives.

# Examples

### Basic
```cpp
#include "BloomFilter.h"

// Create bloomfitler of 100 bits in size.
BloomFilter<100> bloom;

// Insert some items.
bloom.insert(100);
bloom.insert(125);
bloom.insert(128);

bloom.has(100) // returns true
bloom.has(130) // returns false
```

### String
```cpp
#include "BloomFilter.h"

// Create bloomfitler of 100 bits in size.
BloomFilter<100> bloom;

// Insert some items.
bloom.insert("Alice");
bloom.insert("Bob");
bloom.insert("Clare");

bloom.has("Alice") // returns true
bloom.has("Steve") // returns false
```

# More info
- [BloomFilter](https://en.wikipedia.org/wiki/Bloom_filter)
- [xxHash](https://github.com/Cyan4973/xxHash)
- [bitset](https://en.cppreference.com/w/cpp/utility/bitset)
