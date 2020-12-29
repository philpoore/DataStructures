#include "Stack.h"

int main() {
    Stack<int> s;
    s.push(10);
    s.push(11);
    s.push(12);

    while(!s.empty()) {
        std::cout << "top: " << s.top() << "\n";
        s.pop();
    }
}