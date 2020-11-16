#include "Trie.hpp"

TrieNode::TrieNode(char letter, bool end) : letter(letter), end(end) {}
TrieNode::~TrieNode() {
    for (auto& child : children) {
        delete child;
    }
}

void TrieNode::addNode(TrieNode* node) {
    children.push_back(node);
}

TrieNode* TrieNode::getChild(char letter) {
    for (auto& node : children) {
        if (node->letter == letter) {
            return node;
        }
    }
    return nullptr;
}

Trie::Trie() : root(new TrieNode('\0')) {}
Trie::~Trie() {
    delete root;
}

void Trie::insert(std::string word) {
    TrieNode* currentNode = root;
    int n = word.size();
    for (int i = 0; i < n; i++) {
        char c = word[i];
        char isEnd = (i == n - 1);
        TrieNode* child = currentNode->getChild(c);

        if (child != nullptr) {
            if (isEnd) {
                child->end = true;
            }
            currentNode = child;
            continue;
        }

        TrieNode* new_node = new TrieNode(c, isEnd);
        currentNode->addNode(new_node);
        currentNode = new_node;
    }
}

void Trie::enumerateDFS(std::vector<std::string> &results, TrieNode* node, std::string prefix) {
    if (node->letter != '\0') {
        prefix += node->letter;
    }
    if (node->end) {
        results.push_back(prefix);
    }
    for (auto& child : node->children) {
        enumerateDFS(results, child, prefix);
    }
}

/**
 * Wrapper around enumerateDFS
 **/
std::vector<std::string> Trie::enumerate() {
    std::vector<std::string> results;
    enumerateDFS(results, root, "");
    return results;
}

bool Trie::search(std::string word) {
    TrieNode* currentNode = root;
    int n = word.size();
    for (int i = 0; i < n; i++) {
        char c = word[i];
        TrieNode* child = currentNode->getChild(c);
        if (child == nullptr) {
            return false;
        }

        char isEnd = (i == n - 1);
        if (isEnd) {
            return child->end;
        }

        currentNode = child;
    }
    return false;
}