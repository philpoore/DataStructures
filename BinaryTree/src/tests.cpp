#include <stdio.h>
#include <assert.h>
#include <gtest/gtest.h>

#include "BinaryTree.h"

TEST(BinaryTree, create) {
    Node<int>* root = new Node<int>(10);
    int tmp = root->value;
    delete root;
    EXPECT_EQ(tmp, 10);
}


TEST(BinaryTree, insert) {
    Node<int>* root = new Node<int>(10);
    root->insert(11);
    root->insert(12);
    root->insert(13);
    delete root;
}

TEST(BinaryTree, has) {
    Node<int>* root = new Node<int>(10);
    root->insert(11);
    EXPECT_EQ(root->has(10), true);
    EXPECT_EQ(root->has(11), true);
    EXPECT_EQ(root->has(12), false);
    EXPECT_EQ(root->has(13), false);

    root->insert(12);
    root->insert(13);
    
    EXPECT_EQ(root->has(10), true);
    EXPECT_EQ(root->has(11), true);
    EXPECT_EQ(root->has(12), true);
    EXPECT_EQ(root->has(13), true);
    delete root;
}

TEST(BinaryTree, height) {
    Node<int>* root = new Node<int>(10);
    EXPECT_EQ(root->height(), 1);
    root->insert(11);
    EXPECT_EQ(root->height(), 2);
    root->insert(12);
    EXPECT_EQ(root->height(), 2);
    root->insert(13);
    EXPECT_EQ(root->height(), 3);
    delete root;
}

TEST(BinaryTree, min_height) {
    Node<int>* root = new Node<int>(10);
    
    EXPECT_EQ(root->min_height(), 0);
    root->insert(11);
    EXPECT_EQ(root->min_height(), 0);
    root->insert(12);
    EXPECT_EQ(root->min_height(), 1);
    root->insert(13);
    EXPECT_EQ(root->min_height(), 1);
    root->insert(13);
    root->insert(13);
    EXPECT_EQ(root->min_height(), 1);
    root->insert(13);
    EXPECT_EQ(root->min_height(), 2);
    delete root;
}