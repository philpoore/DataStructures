#pragma once

#include "../../DoubleLinkedList/src/DoubleLinkedList.h"

template<typename T>
class Queue {
    DoubleLinkedList<T> list;
public:
    Queue() : list() {}

    void push(T value) {
        list.push_back(value);
    }

    void pop() {
        list.pop_front();
    }

    bool empty() { return list.empty(); }
    int size() { return list.size(); }

    T front() { return list.front(); }
    T back() { return list.back(); }    
};