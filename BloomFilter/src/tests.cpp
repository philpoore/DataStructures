#include <stdio.h>
#include <assert.h>
#include <gtest/gtest.h>
#include <string>

#include "BloomFilter.h"

TEST(Hash, same) {
    int A = 56;
    int B = 56;

    void* buffer = &A;
    int size = sizeof(A);

    int h11 = XXH64(buffer, size, 0);
    int h12 = XXH64(buffer, size, 1);
    int h13 = XXH64(buffer, size, 2);

    buffer = &B;
    int h21 = XXH64(buffer, size, 0);
    int h22 = XXH64(buffer, size, 1);
    int h23 = XXH64(buffer, size, 2);

    EXPECT_EQ(h11, h21);
    EXPECT_EQ(h12, h22);
    EXPECT_EQ(h13, h23);
}



TEST(Hash, diff) {
    int A = 56;
    int B = 57;

    void* buffer = &A;
    int size = sizeof(A);

    int h11 = XXH64(buffer, size, 0);
    int h12 = XXH64(buffer, size, 1);
    int h13 = XXH64(buffer, size, 2);

    buffer = &B;
    int h21 = XXH64(buffer, size, 0);
    int h22 = XXH64(buffer, size, 1);
    int h23 = XXH64(buffer, size, 2);

    EXPECT_NE(h11, h21);
    EXPECT_NE(h12, h22);
    EXPECT_NE(h13, h23);
}

TEST(Hash, hashes_diff) {
    int A = 56;

    void* buffer = &A;
    int size = sizeof(A);

    int h1 = XXH64(buffer, size, 0);
    int h2 = XXH64(buffer, size, 1);
    int h3 = XXH64(buffer, size, 2);

    EXPECT_NE(h1, h2);
    EXPECT_NE(h1, h3);
    EXPECT_NE(h2, h3);
}


TEST(Hash, hash_string_eq) {
    std::string a = "Hello";
    std::string b = "Hello";

    int h11 = XXH64(a.data(), a.size(), 0);
    int h12 = XXH64(a.data(), a.size(), 1);
    int h13 = XXH64(a.data(), a.size(), 2);

    int h21 = XXH64(b.data(), b.size(), 0);
    int h22 = XXH64(b.data(), b.size(), 1);
    int h23 = XXH64(b.data(), b.size(), 2);

    EXPECT_EQ(h11, h21);
    EXPECT_EQ(h12, h22);
    EXPECT_EQ(h13, h23);
}

TEST(Hash, hash_string_ne) {
    std::string a = "Hello";
    std::string b = "Not Hello";

    int h11 = XXH64(a.data(), a.size(), 0);
    int h12 = XXH64(a.data(), a.size(), 1);
    int h13 = XXH64(a.data(), a.size(), 2);

    int h21 = XXH64(b.data(), b.size(), 0);
    int h22 = XXH64(b.data(), b.size(), 1);
    int h23 = XXH64(b.data(), b.size(), 2);

    EXPECT_NE(h11, h21);
    EXPECT_NE(h12, h22);
    EXPECT_NE(h13, h23);
}


TEST(BloomFilter, create) {
    BloomFilter<1000> bloom;
    EXPECT_EQ(bloom.size(), 0);
}

TEST(BloomFilter, insert) {
    BloomFilter<1000> bloom;
    EXPECT_EQ(bloom.size(), 0);
    int r = rand();
    EXPECT_FALSE(bloom.has(r));
    bloom.insert(r);
    EXPECT_TRUE(bloom.has(r));
    EXPECT_EQ(bloom.size(), 1);
}


TEST(BloomFilter, insert_string) {
    BloomFilter<1000> bloom;
    EXPECT_EQ(bloom.size(), 0);
    std::string a = "Hello world";
    EXPECT_FALSE(bloom.has(a));
    bloom.insert(a);
    EXPECT_TRUE(bloom.has(a));
    EXPECT_EQ(bloom.size(), 1);
}

TEST(BloomFilter, insert_many) {
    BloomFilter<64> bloom;
    EXPECT_EQ(bloom.size(), 0);

    std::vector<std::string> names = {
        "Alice",
        "Bob",
        "Clair",
        "Dave",
        "Edmund",
        "Fiona",
        "Elle",
        "Frank",
        "George"
    };

    for (auto& name : names)
        bloom.insert(name);
    
    EXPECT_EQ(bloom.size(), names.size());

    for (auto& name : names)
        EXPECT_TRUE(bloom.has(name));

    for (auto& name : names)
        reverse(name.begin(), name.end());
    
    for (auto& name : names)
        EXPECT_FALSE(bloom.has(name)) << name;
}


TEST(Examples, basic) {
    BloomFilter<100> bloom;

    // Insert some items.
    bloom.insert(100);
    bloom.insert(125);
    bloom.insert(128);

    EXPECT_TRUE(bloom.has(100));
    EXPECT_FALSE(bloom.has(130));
}

TEST(Examples, string) {
    BloomFilter<100> bloom;

    bloom.insert("Alice");
    bloom.insert("Bob");
    bloom.insert("Clare");

    EXPECT_TRUE(bloom.has("Alice"));
    EXPECT_FALSE(bloom.has("Alan"));
    EXPECT_FALSE(bloom.has("Steve"));
}