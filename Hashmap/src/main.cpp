#include <iostream>

#include "Hashmap.h"

int main() {
    Hashmap<int, int> map;

    map[1] = 21;
    map[2] = 22;
    map[3] = 23;
    map[4] = 24;
    map[5] = 25;

    map[4] = 240;

    map.print();

    for (auto it : map) {
        std::cout << "key: " << it.first << " value: " << it.second << "\n";
    }

    std::cout << "map[10]? " << map[10] << "\n";
    std::cout << "map[11]? " << map[11] << "\n";

    std::cout << "map count 10? " << map.count(10) << "\n";
    std::cout << "map count 30? " << map.count(30) << "\n";

    // String hashmap
    Hashmap<std::string, std::string> smap;

    smap["Hello"] = "world";
    smap["name"] = "Phil Poore";

    smap.print();

    for (auto it : smap) {
        std::cout << "-> key: " << it.first << " value: " << it.second << "\n";
    }
}