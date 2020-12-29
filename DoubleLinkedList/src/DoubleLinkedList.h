#pragma once

#include <iostream>

template <class T>
struct ListNode
{
    T value;
    ListNode<T> *next = nullptr;
    ListNode<T> *prev = nullptr;
    ListNode() : value(T()) {}
    ListNode(T value) : value(value) {}
};


template <class T>
class DoubleLinkedList
{
    ListNode<T> *head = nullptr;
    ListNode<T> *tail = nullptr;
    int _size = 0;

public:
    class iterator;

    DoubleLinkedList() {}
    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            ListNode<T> *current = head;
            head = head->next;
            delete current;
        }
    }

    T front() { return head->value; }
    T back() { return tail->value; }
    bool empty() { return head == nullptr; }
    int size() { return _size; }

    void push_front(T value)
    {
        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        if (!tail) {
            tail = newNode;
        }

        head = newNode;
        _size++;
    }

    void push_back(T value)
    {
        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->prev = tail;
        if (tail) {
            tail->next = newNode;
        }
        if (!head) {
            head = newNode;
        }
        tail = newNode;
        _size++;
    }

    void pop_front()
    {
        if (head == nullptr)
            return;

        ListNode<T> *next = head->next;
        delete head;
        head = next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        _size--;
    }

    void pop_back()
    {
        if (tail == nullptr)
            return;

        ListNode<T> *prev = tail->prev;
        delete tail;
        tail = prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        _size--;
    }

    void insert(int pos, T value) {
        if (pos == 0) {
            push_front(value);
            return;
        }
        if (pos == size() - 1) {
            push_back(value);
            return;
        }
        int i = 0;
        ListNode<T>* tmp = head;
        while (i < pos - 1 && tmp) {
            tmp = tmp->next;
            i++;
        }

        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->prev = tmp;
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        tmp->next = newNode;
        _size++;
    }

    void print() {
        ListNode<T>* tmp = head;
        std::cout << "DoubleLinkedList: ";
        while(tmp) {
            std::cout << tmp->value;
            if (tmp->next)
                std::cout << " -> ";
            tmp = tmp->next;
        }
        std::cout << "\n";
    }
    void reverse_print() {
        ListNode<T>* tmp = tail;
        std::cout << "DoubleLinkedList: ";
        while(tmp) {
            std::cout << tmp->value;
            if (tmp->prev)
                std::cout << " -> ";
            tmp = tmp->prev;
        }
        std::cout << "\n";
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    class iterator
    {
        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef ListNode<T>* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(pointer ptr) : ptr_(ptr) { }
            self_type operator++() { self_type i = *this; ptr_ = ptr_->next; return i; }
            self_type operator++(int junk) { ptr_ = ptr_->next; return *this; }
            reference operator*() { return ptr_->value; }
            pointer operator->() { return ptr_; }
            bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
            bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
        private:
            pointer ptr_;
    };
};