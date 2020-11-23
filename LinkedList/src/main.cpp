#include <iostream>

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

int main()
{
    // Linked list of ints.
    LinkedList<int> list;
    list.push_front(10);
    list.push_front(11);
    list.push_front(12);
    list.push_back(9);
    list.push_back(8);
    list.push_back(7);
    list.push_front(13);
    list.push_front(14);

    std::cout << "value front: " << list.front() << std::endl;
    std::cout << "value back: " << list.back() << std::endl;
    while (!list.empty())
    {
        int value = list.front();
        list.pop();
        std::cout << "value: " << value << std::endl;
    }

    // Linked list of strings.
    LinkedList<std::string> list_strings;
    list_strings.push_front("world");
    list_strings.push_front("Hello");
    list_strings.push_back("more goes here");

    while (!list_strings.empty())
    {
        std::string value = list_strings.front();
        list_strings.pop();
        std::cout << "value string: " << value << std::endl;
    }

    // Reverse linked list
    LinkedList<int> list2;
    list2.push_front(10);
    list2.push_front(11);
    list2.push_front(12);
    list2.reverse();
    while (!list2.empty()) {
        int value = list2.front();
        list2.pop();
        std::cout << "value list2: " << value << std::endl;
    }
    return 0;
}