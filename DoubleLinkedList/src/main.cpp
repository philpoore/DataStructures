#include <iostream>

#include "DoubleLinkedList.h"

#include <algorithm>

int main()
{
    // Double Linked list of ints.
    DoubleLinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(rand() % 20);
    }

    list.print();

    for (auto& v : list) {
        std::cout << "v: " << v << "\n";
    }

    for (auto& v : list) {
        if (v % 2 == 0) {
            v = 25;
        }
        std::cout << "v: " << v << "\n";
    }
    list.print();

    auto it = list.begin();
    while(it != list.end()) {
        std::cout << "v: " << *it << "\n";
        it++;
    }

    return 0;
}