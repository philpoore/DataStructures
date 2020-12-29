#pragma once

template <class T>
struct ListNode
{
    T value;
    ListNode<T> *next;
    ListNode(T value) : value(value) {}
};


template <class T>
class LinkedList
{
    ListNode<T> *head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList()
    {
        while (head != nullptr)
        {
            ListNode<T> *current = head;
            head = head->next;
            delete current;
        }
    }
    void push_front(T value)
    {
        ListNode<T> *newNode = new ListNode<T>(value);
        newNode->next = head;

        head = newNode;
    }

    void push_back(T value)
    {
        ListNode<T> *newNode = new ListNode<T>(value);
        ListNode<T> *current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
  
        current->next = newNode;
    }

    void pop()
    {
        if (head == nullptr)
            return;

        ListNode<T> *next = head->next;
        delete head;
        head = next;
    }

    T front() { return head->value; }
    T back() {
        ListNode<T> *current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        return current->value;
    }
    bool empty() { return head == nullptr; }

    void reverse() {
        ListNode<T> *a = nullptr;

        ListNode<T> *b = head;
        if (b == nullptr) return;

        ListNode<T> *c = b->next;
        if (c == nullptr) return;

        while (b) {
            b->next = a;
            a = b;
            b = c;
            c = c ? c->next : c;
        }
        head = a;
    }
};