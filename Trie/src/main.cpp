#include <iostream>
#include <string>

#include "Trie.hpp"


int main() {
    Trie t;

    // Insert words.
    t.insert("hello");
    t.insert("hell");
    t.insert("help");
    t.insert("bat");

    // Enumerate all the words.
    for (auto word : t.enumerate()) {
        std::cout << "word: " << word << std::endl;
    }

    // Check if a word exists.
    std::cout << "has word foo : " << t.search("foo") << std::endl;
    std::cout << "has word hell : " << t.search("hell") << std::endl;
}