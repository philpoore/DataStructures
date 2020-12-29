#include <stdio.h>
#include <assert.h>
#include <gtest/gtest.h>

#include "Stack.h"


TEST(Stack, create_int) {
    Stack<int> s;
    ASSERT_EQ(s.size(), 0);
}

TEST(Stack, create_long_long) {
    Stack<long long> s;
}

TEST(Stack, create_string) {
    Stack<long long> s;
}

TEST(Stack, create_compound) {
    Stack<std::pair<int, int>> s;
}

TEST(Stack, push_pop) {
    Stack<int> s;
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto& a : v) {
        s.push(a);
    }

    ASSERT_EQ(s.size(), v.size());

    for (int i = 0; i < v.size(); i++) {
        ASSERT_EQ(s.top(), v[v.size() - i - 1]);
        s.pop();
    }
    ASSERT_EQ(s.size(), 0);
}