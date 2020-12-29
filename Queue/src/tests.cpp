#include <stdio.h>
#include <assert.h>
#include <gtest/gtest.h>

#include "Queue.h"


TEST(Queue, create_int) {
    Queue<int> q;
    ASSERT_EQ(q.size(), 0);
}

TEST(Queue, create_long_long) {
    Queue<long long> q;
}

TEST(Queue, create_string) {
    Queue<long long> q;
}

TEST(Queue, create_compound) {
    Queue<std::pair<int, int>> q;
}

TEST(Queue, push_pop) {
    Queue<int> q;
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto& a : v) {
        q.push(a);
    }

    ASSERT_EQ(q.size(), v.size());

    for (int i = 0; i < v.size(); i++) {
        ASSERT_EQ(q.front(), v[i]);
        q.pop();
    }
    ASSERT_EQ(q.size(), 0);
}