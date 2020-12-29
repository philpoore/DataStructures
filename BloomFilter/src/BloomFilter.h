#pragma once

#include <functional>
#include <string>
#include <bitset>

#include "../3rd/xxHash/xxhash.h"

#define DEBUG false

template <int N>
class BloomFilter {
    std::bitset<N> data;
    unsigned long long _size = 0;
public:
    BloomFilter() {}

    unsigned long long size() {
        return _size;
    }

    void insert(const char* ptr, int size) {
        int h1 = XXH64(ptr, size, 0) % N;
        int h2 = XXH64(ptr, size, 1) % N;
        int h3 = XXH64(ptr, size, 2) % N;
        #if DEBUG
        std::cout << "h1: " << h1 << " h2: " << h2 << " h3: " << h3 << "\n";
        #endif 
        data.set(h1, true);
        data.set(h2, true);
        data.set(h3, true);
        _size++;
    }

    template <typename T>
    void insert(const T& t) {
        insert((char*)&t, sizeof(T));
    }

    void insert(std::string s) {
        insert(s.data(), s.size());
    }

    bool has(const char* ptr, int size) {
        int h1 = XXH64(ptr, size, 0) % N;
        int h2 = XXH64(ptr, size, 1) % N;
        int h3 = XXH64(ptr, size, 2) % N;

        #if DEBUG
        std::cout << "h1: " << h1 << " h2: " << h2 << " h3: " << h3 << "\n";
        #endif

        return data.test(h1) && data.test(h2) && data.test(h3);
    }

    template <typename T>
    bool has(const T &t) {
        return has((char*)&t, sizeof(T));
    }

    bool has(std::string s) {
        return has(s.data(), s.size());
    }
};