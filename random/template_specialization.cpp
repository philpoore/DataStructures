#include <string>
#include <iostream>

template<typename T>
std::string to_string(T value) {
    return std::to_string(value);
}

template<>
std::string to_string(std::string value) {
    return value;
}

int main() {
    std::cout << to_string(20) << "\n";
    std::cout << to_string(std::string("hello")) << "\n";
}