#include <stdio.h>
#include <assert.h>
#include <gtest/gtest.h>

#include "DoubleLinkedList.h"

TEST(DoubleLinkedList, Create) {
    DoubleLinkedList<int> list;
}

TEST(DoubleLinkedList, size) {
    DoubleLinkedList<int> list;
    ASSERT_EQ(list.size(), 0);
    list.push_front(12);
    ASSERT_EQ(list.size(), 1);
    list.push_front(12);
    ASSERT_EQ(list.size(), 2);
    list.pop_front();
    ASSERT_EQ(list.size(), 1);
    list.pop_front();
    ASSERT_EQ(list.size(), 0);
    list.pop_front();
    ASSERT_EQ(list.size(), 0);
}

TEST(DoubleLinkedList, empty) {
    DoubleLinkedList<int> list;
    ASSERT_EQ(list.empty(), true);
    list.push_front(12);
    ASSERT_EQ(list.empty(), false);
    list.pop_front();
    ASSERT_EQ(list.empty(), true);
}

TEST(DoubleLinkedList, push_front) {
    DoubleLinkedList<int> list;
    list.push_front(10);
    ASSERT_EQ(list.front(), 10);
    ASSERT_EQ(list.back(), 10);
}

TEST(DoubleLinkedList, push_front_2) {
    DoubleLinkedList<int> list;
    list.push_front(11);
    list.push_front(12);
    ASSERT_EQ(list.front(), 12);
    ASSERT_EQ(list.back(), 11);
}

TEST(DoubleLinkedList, push_back) {
    int A = 13;
    DoubleLinkedList<int> list;
    list.push_back(A);
    ASSERT_EQ(list.front(), A);
    ASSERT_EQ(list.back(), A);
}

TEST(DoubleLinkedList, push_back_2) {
    int A = 14, B = 15;
    DoubleLinkedList<int> list;
    list.push_back(A);
    list.push_back(B);
    ASSERT_EQ(list.front(), A);
    ASSERT_EQ(list.back(), B);
}

TEST(DoubleLinkedList, pop_front) {
    int A = 16, B = 17;
    DoubleLinkedList<int> list;
    list.push_front(A);
    ASSERT_EQ(list.front(), A);
    list.push_front(B);
    ASSERT_EQ(list.front(), B);
    list.pop_front();
    ASSERT_EQ(list.front(), A);
}

TEST(DoubleLinkedList, insert) {
    DoubleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.insert(1, 4);

    ASSERT_EQ(list.front(), 1);
    list.pop_front();
    ASSERT_EQ(list.front(), 4);
    list.pop_front();
    ASSERT_EQ(list.front(), 2);
    list.pop_front();
    ASSERT_EQ(list.front(), 3);
}

TEST(DoubleLinkedList, string) {
    DoubleLinkedList<std::string> list;
    list.push_front("Hello");
    ASSERT_EQ(list.front(), "Hello");
}

TEST(DoubleLinkedList, string_2) {
    DoubleLinkedList<std::string> list;
    std::vector<std::string> words = {
        "Hello",
        "World",
        "How's",
        "it",
        "going?"
    };
    for (auto& word : words) {
        list.push_back(word);
    }

    ASSERT_EQ(list.front(), "Hello");
    ASSERT_EQ(list.back(), "going?");
    while(!list.empty()) {
        ASSERT_EQ(list.back(), words.back());
        words.pop_back();
        list.pop_back();
    }
}

TEST(DoubleLinkedList, string_3) {
    DoubleLinkedList<std::string> list;
    std::vector<std::string> words = {
        "Hello",
        "World",
        "How's",
        "it",
        "going?"
    };
    for (auto& word : words) {
        list.push_front(word);
    }

    ASSERT_EQ(list.front(), "going?");
    ASSERT_EQ(list.back(), "Hello");
    while(!list.empty()) {
        ASSERT_EQ(list.front(), words.back());
        words.pop_back();
        list.pop_front();
    }
}