# Vector

Dynamic Array cpp implementation.

# Features
- Iterator support with `begin()` and `end()`
- Creation from `initializer_list`.

# Complexity
- Amortized constant `push_back`
- Constant element access using `operator[]`
- Insert and Erase complexity is proportional to distance from end

# Example
```cpp
// Create vector
Vector<int> v = {1, 2, 3, 4, 5, 6};

// Add some more items.
v.push_back(7);
v.push_back(8);

// Check the size.
assert(v.size() == 8);

// Iterator support
for (auto& a : v)
    if (a % 3 == 0) a *= -1;

// Display items
for (auto& a : v)
    std::cout << a << "\n";
```