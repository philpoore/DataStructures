#include <iostream>
#include <algorithm>

#include "Vector.h"

int main() {
    Vector<int> v;
    v.reserve(20);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.print();
    
    std::cout << "front : " << v.front() << "\n";
    std::cout << "back  : " << v.back() << "\n";

    v.insert(0, 100);
    v.insert(1, 101);
    v.insert(2, 102);
    v.insert(3, 103);

    for (int i = 0; i < v.size(); i++) {
        std::cout << i << " = " << v[i] << "\n";
    }

    // Iterator
    for (auto& a : v) {
        if (a >= 100) a *= -1;
    }
    for (auto& a : v) {
        std::cout << a << "\n";
    }

    
    Vector<int> v2 = {1, 2, 3, 4, 5};
    for (auto& a : v2)
        std::cout << "vector: " << a << "\n";

    auto max = *std::max_element(v2.begin(), v2.end());
    auto min = *std::min_element(v2.begin(), v2.end());
    
    std::cout << "max: " << max << "\n";
    std::cout << "min: " << min << "\n";

    Vector<std::string> v3 = {
        "hello",
        "world",
        "more",
        "here"
    };

    for (auto& word : v3) {
        std::cout << "word: " << word << "\n";
    }
}