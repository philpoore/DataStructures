#pragma once

#include <utility>
#include <vector>

#include "../3rd/xxHash/xxhash.h"

#include "../../DoubleLinkedList/src/DoubleLinkedList.h"

#define DEBUG 0


// to_string helper functions
template<typename T>
std::string to_string(T value) {
    return std::to_string(value);
}

template<>
std::string to_string(std::string value) {
    return value;
}


template<typename K, typename V>
class Hashmap {
    typedef std::pair<K, V> pair_type;
    typedef DoubleLinkedList<pair_type> list_type;

    unsigned int num_buckets;
    unsigned int _size;
    std::vector<list_type> buckets;

public:
    Hashmap() : num_buckets(10), _size(0) {
        buckets.resize(num_buckets);
    }
    
    void insert(const K& key, const V& value) {
        list_type& list = get_list(key);
        
        for (auto& it : list) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
        
        // Insert new item.
        list.push_back(std::make_pair(key, value));
        _size++;
    }

    const V& get(const K& key) {
        list_type& list = get_list(key);

        for (auto& it : list) {
            if (it.first == key) {
                return it.second;
            }
        }

        // Throw key not found.
        throw std::out_of_range("could not get that key");
    }

    int count(const K& key) {
        list_type& list = get_list(key);

        for (auto& it : list) {
            if (it.first == key) {
                return 1;
            }
        }

        return 0;
    }

    int size() { return _size; }
    bool empty() { return _size == 0; }

    V& operator[] (const K& key) {
        list_type& list = get_list(key);

        for (auto& it : list) {
            if (it.first == key) {
                return it.second;
            }
        }
        
        list.push_back(std::make_pair(key, V()));

        return list.tail->value.second;
    }

private:
    template<typename T>
    unsigned int hash(const T& key) {
        return XXH64((void*)&key, sizeof(K), 0);
    }
    
    unsigned int hash(const std::string& key) {
        return XXH64((void*)key.data(), key.size(), 0);
    }

    list_type& get_list(const K& key) {
        unsigned int h = hash(key);
        unsigned int bucket_id = h % num_buckets;

        #if DEBUG
        std::cout << "K: " << key << " hash: " << h << "\n";
        std::cout << "bucket_id: " << bucket_id << "\n";
        #endif
        
        return buckets[bucket_id];
    }

public:
    void print() {
        int i = 0;

        auto format = [&](const pair_type& p){
            return to_string(p.first) + "," + to_string(p.second);
        };

        for (list_type& list : buckets) {
            std::cout << "Bucket #" << i << " : ";
            list.print(format);
            i++;
        }
    }

    
    class iterator;

    iterator begin() {
        for (int i = 0; i < num_buckets; i++) {
            auto& head = buckets[i].head;
            if (head) {
                return iterator(this, head, i);
            }
        }
        
        return iterator(this, nullptr, 0);
    }

    iterator end() {
        return iterator(this, nullptr, num_buckets + 1);
    }

    class iterator
    {
        public:
            typedef iterator self_type;
            typedef pair_type value_type;
            typedef pair_type& reference;
            typedef Hashmap<K, V>* hashmap_pointer;
            typedef ListNode<pair_type>* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;

            iterator(const hashmap_pointer& hashmap_ptr, const pointer& ptr, int bucket_id)
                : ptr_(ptr), hashmap_ptr(hashmap_ptr), bucket_id(bucket_id) {}
            self_type operator++() {
                self_type i = *this;
                advance();
                return i;
            }
            self_type operator++(int junk) {
                advance();
                return *this;
            }
            reference operator*() { return ptr_->value; }
            pointer operator->() { return ptr_; }
            bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
            bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
        private:
            pointer ptr_;
            hashmap_pointer hashmap_ptr;
            int bucket_id;

            void advance() {
                ptr_ = ptr_->next;

                if (ptr_) return;

                // Got to the end of the list, find the next bucket to
                // use, otherwise set ptr_ to nullptr
                do {
                    bucket_id++;
                    if (bucket_id >= hashmap_ptr->num_buckets)
                        break;
                    
                    ptr_ = hashmap_ptr->buckets[bucket_id].head;
                    if (ptr_)
                        break;
                } while(!ptr_);
            }
    };
};


