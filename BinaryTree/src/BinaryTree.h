#include <iostream>
#include <cmath>

#include "../../Queue/src/Queue.h"
#include "../../Stack/src/Stack.h"

template<typename T>
class Node {

public:

    Node* left = nullptr;
    Node* right = nullptr;
    T value;
    Node() {value = T();}
    Node(T value) : value(value) {}
    ~Node() { delete left; delete right; }

    int height() {
        if (!left && !right) {
            return 1;
        } else if (left) {
            return left->height() + 1;
        } else if (right) {
            return right->height() + 1;
        } else {
            return std::max(left->height(), right->height()) + 1;
        }
    }

    int min_height() {
        if (!left || !right) {
            return 0;
        } else {
            return std::min(left->min_height(), right->min_height()) + 1;
        }
    }

    void insert(T value) {
        Node* new_node = new Node(value);
        insert(new_node);
    }

    void insert(Node* new_node) {
        Queue<Node*> q;
        q.push(this);

        while(!q.empty()) {
            Node* tmp = q.front();
            q.pop();

            if (tmp->left) {
                q.push(tmp->left);
            } else {
                tmp->left = new_node;
                return;
            }

            if (tmp->right) {
                q.push(tmp->right);
            } else {
                tmp->right = new_node;
                return;
            }
        }
    }

    Node* erase(T value) {
        if (this->value == value) {
            // Remove root
            auto min_height_left = left->min_height();
            auto min_height_right = right->min_height();

            // Merge the bigger tree into the smallest.
            Node* replace_node;
            if (min_height_left <= min_height_right) {
                left->insert(right);
                replace_node = left;
            } else {
                right->insert(left);
                replace_node = right;
            }

            return replace_node;
        }

        
        Queue<std::pair<Node*, Node*>> q;
        q.push({this, nullptr});
        while(!q.empty()) {
            std::pair<Node*, Node*> p = q.front();
            q.pop();

            Node* tmp = p.first;
            Node* parent = p.second;

            if (tmp->value == value) {
                // Found node to remove
                Node* replace_node = nullptr;

                if (tmp->left && tmp->right) {
                    // Two children

                    // Find the tree with the lowest min_height
                    auto min_height_left = tmp->left->min_height();
                    auto min_height_right = tmp->right->min_height();

                    // Merge the bigger tree into the smallest.
                    if (min_height_left <= min_height_right) {
                        tmp->left->insert(tmp->right);
                        replace_node = tmp->left;
                    } else {
                        tmp->right->insert(tmp->left);
                        replace_node = tmp->right;
                    }
                } else if (tmp->left) {
                    // Left child only
                    replace_node = tmp->right;
                } else if (tmp->right) {
                    // Right child only
                    replace_node = tmp->right;
                }

                if (parent->left == tmp) {
                    parent->left = replace_node;
                } else if (parent->right == tmp) {
                    parent->right = replace_node;
                }

                tmp->left = nullptr;
                tmp->right = nullptr;
                delete tmp;

                return this;
            }

            if (tmp->left) {
                q.push({tmp->left, tmp});
            }

            if (tmp->right) {
                q.push({tmp->right, tmp});
            }
        }

        return this;
    }

    // Returns true if the value is present in the the tree.
    bool has(T value) {
        if (this->value == value) return true;

        if (this->left && this->left->has(value)) return true;
        if (this->right && this->right->has(value)) return true;

        return false;
    }

    void print() {
        visit_inorder([](T a){
            std::cout << a << " ";
        });
        std::cout << "\n";
    }

    // Visit each node in order, passing each value to visit function.
    template<typename F>
    void visit_inorder(F &&visit) {
        visit_inorder_rec(this, visit);
    }

private:
    template<typename F>
    const static void visit_inorder_rec(Node* root, F &&visit) {
        if (!root) return;

        if (root->left)
            visit_inorder_rec(root->left, visit);

        visit(root->value);

        if (root->right)
            visit_inorder_rec(root->right, visit);
    }
};