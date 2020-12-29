#pragma once

#include "../../DoubleLinkedList/src/DoubleLinkedList.h"

template<typename T>
class Stack {
    DoubleLinkedList<T> list;
public:
    Stack() : list() {}

    void push(T value) {
        list.push_back(value);
    }

    void pop() {
        list.pop_back();
    }

    bool empty() { return list.empty(); }
    int size() { return list.size(); }

    T top() { return list.back(); }    
};