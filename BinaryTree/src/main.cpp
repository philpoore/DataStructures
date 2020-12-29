#include "BinaryTree.h"

int main() {
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(11);
    root->right = new Node<int>(12);
    root->print();

    root->insert(34);
    root->insert(35);
    root->insert(36);
    root->insert(36);
    root->insert(36);
    root->insert(36);
    root->print();

    std::cout << "height: " << root->height() << "\n";
    std::cout << "min_height: " << root->min_height() << "\n";

    auto test_has = [&](int v){
        std::cout << "has " << v << " : " << (root->has(v) ? "yes" : "no") << "\n";
    };

    test_has(35);
    test_has(25);
    test_has(15);

    root->print();
    root = root->erase(11);
    root->print();

    root = root->erase(10);
    root->print();

    std::cout << "height: " << root->height() << "\n";
    std::cout << "min_height: " << root->min_height() << "\n";
}