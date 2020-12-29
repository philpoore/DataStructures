#include "Queue.h"

int main() {
    Queue<int> q;
    q.push(10);
    q.push(11);
    q.push(12);

    while(!q.empty()) {
        std::cout << "q: " << q.front() << "\n";
        q.pop();
    }
}