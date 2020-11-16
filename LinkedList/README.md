# Linked List

Very basic linked list written in cpp.

```cpp
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
```