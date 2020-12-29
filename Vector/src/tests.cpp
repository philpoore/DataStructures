#include <stdio.h>
#include <assert.h>
#include <gtest/gtest.h>

#include "Vector.h"

TEST(Vector, create) {
    Vector<int> v;
    ASSERT_EQ(v.size(), 0);
}

TEST(Vector, create_init) {
    Vector<int> v = {1, 2, 3};
    ASSERT_EQ(v.size(), 3);
    ASSERT_EQ(v[0], 1);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 3);
}

TEST(Vector, push_back) {
    Vector<int> v;
    v.push_back(10);
    ASSERT_EQ(v.size(), 1);
    ASSERT_EQ(v.back(), 10);
    v.push_back(11);
    ASSERT_EQ(v.size(), 2);
    ASSERT_EQ(v.back(), 11);
}

TEST(Vector, back) {
    Vector<int> v;
    v.push_back(10);
    ASSERT_EQ(v.back(), 10);
    v.push_back(11);
    ASSERT_EQ(v.back(), 11);
}

TEST(Vector, pop_back) {
    Vector<int> v;
    v.push_back(10);
    v.push_back(11);
    ASSERT_EQ(v.size(), 2);
    ASSERT_EQ(v.back(), 11);
    v.pop_back();
    ASSERT_EQ(v.size(), 1);
    ASSERT_EQ(v.back(), 10);
}

TEST(VectorString, create) {
    Vector<std::string> v;
    v.push_back("Hello");
    v.push_back("world");
    ASSERT_EQ(v.size(), 2);
    ASSERT_EQ(v[0], "Hello");
    ASSERT_EQ(v[1], "world");
}