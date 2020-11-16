#pragma once

#include <vector>
#include <string>

#include "Trie.hpp"

class TrieNode {
public:
    char letter;
    bool end;
    std::vector<TrieNode*> children;
    TrieNode(char letter, bool end = false);
    ~TrieNode();

    void addNode(TrieNode* node);

    TrieNode* getChild(char letter);
};

class Trie {
    TrieNode* root;
    void enumerateDFS(std::vector<std::string> &results, TrieNode* node, std::string prefix);

public:
    Trie();
    ~Trie();

    void insert(std::string word);
    std::vector<std::string> enumerate();
    bool search(std::string word);
};