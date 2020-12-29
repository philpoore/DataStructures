#include <iostream>

#include "BloomFilter.h"

int main() {
    using namespace std::literals::string_literals;

    BloomFilter<1000> bloom;

    // Insert some items.
    bloom.insert("Alice"s);
    bloom.insert("Bob"s);
    bloom.insert("Clare"s);
    
    auto has_test = [&](const std::string s) {
        bool has = bloom.has(s);
        std::cout << "Has " << s << "? " << (has ? "true" : "false") << "\n";
    };

    has_test("Alice"s);
    has_test("Bob"s);
    has_test("Steve"s);

    bloom.insert("Steve"s);

    has_test("Steve"s);
}