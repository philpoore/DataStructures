#pragma once

#include <cstdlib>
#include <cstring>
#include <iostream>


#define DEBUG true

#define debug(a) std::cout << a << "\n";



#define VECTOR_POP_BACK_RESIZE false
#define VECTOR_INIT_CAPACITY 2



template <typename T>
class Vector {
    int _size;
    int _capacity;
    T* _data;

public:
    class iterator;

    Vector();
    Vector(int capacity);
    Vector(std::initializer_list<T> init);

    ~Vector();
    bool empty();
    int size();
    int capacity();

    void reserve(int n);
    void push_back(T value);
    void pop_back();

    T operator[](int i);

    T at(int i);
    T front();
    T back();

    void clear();

    void insert(int i, T value);

    void erase(int i);

    iterator begin();
    iterator end();

    class iterator
    {
        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(pointer ptr) : ptr_(ptr) { }
            self_type operator++() { self_type i = *this; ptr_++; return i; }
            self_type operator++(int junk) { ptr_++; return *this; }
            reference operator*() { return *ptr_; }
            pointer operator->() { return ptr_; }
            bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
            bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
        private:
            pointer ptr_;
    };

private:
    void resize(int new_capacity);
    void resizeUp();
    void resizeDown();

public:
    // Utilities
    void print();
};






template <typename T>
Vector<T>::Vector() : _size(0), _capacity(VECTOR_INIT_CAPACITY), _data(nullptr) {
    _data = (T*)malloc(sizeof(T) * _capacity);
};

template <typename T>
Vector<T>::Vector(int capacity) : _size(0), _capacity(capacity), _data(nullptr) {
    _data = (T*)malloc(sizeof(T) * _capacity);
};

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) : _size(0), _capacity(init.size()), _data(nullptr) {
    _data = (T*)malloc(sizeof(T) * _capacity);
    for (auto& a : init) {
        _data[_size++] = a;
    }
};

template <typename T>
Vector<T>::~Vector() {
    free(_data);
}

template <typename T>
bool Vector<T>::empty() { return _size == 0; }

template <typename T>
int Vector<T>::size() { return _size; }
template <typename T>
int Vector<T>::capacity() { return _capacity; }

template <typename T>
void Vector<T>::reserve(int n) {
    if (n <= _capacity) return;
    resize(n);
}

template <typename T>
void Vector<T>::push_back(T value) {
    if (_size + 1 > _capacity) {
        resizeUp();
    }
    _data[_size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (_size == 0) return;
    _size--;

    #if VECTOR_POP_BACK_RESIZE
    /*
        If size is less than 25% of capacity, resize down by 50%.
        This stops the bounce of resizing up and down when adding
        and removing one element when size is near a resize boundrey.
    */
    if (_size < (_capacity >> 2)) {
        resizeDown();
    }
    #endif
}

template <typename T>
T Vector<T>::operator[](int i) { return _data[i]; }

template <typename T>
T Vector<T>::at(int i) {
    if (i >= _size) {
        throw std::out_of_range("out of bounds");
    }
    return _data[i];
}

template <typename T>
T Vector<T>::front() { return at(0); }

template <typename T>
T Vector<T>::back() { return at(_size - 1); }

template <typename T>
void Vector<T>::clear() {
    _size = 0;
}

template <typename T>
void Vector<T>::insert(int i, T value) {
    if (i >= _size) {
        push_back(value);
        return;
    }

    if (_size + 1 > _capacity) {
        resizeUp();
    }
    
    // Create space for new item by moving all elements along.
    int n = _size - i;
    T* from = &_data[i];
    T* to = &_data[i + 1];
    std::memmove(to, from, sizeof(T) * n);
    
    // Insert new value.
    _data[i] = value;
    _size++;
}

template <typename T>
void Vector<T>::erase(int i) {
    if (i >= _size) {
        return;
    }

    // Copy left the data.
    int n = _size - i;
    T* from = &_data[i + 1];
    T* to = &_data[i];
    std::memmove(to, from, sizeof(T) * n);

    _size--;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return iterator(_data);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(_data + _size);
}

template <typename T>
void Vector<T>::resize(int new_capacity) {
    if (new_capacity <= 0) return;
    #if DEBUG
        debug("Resizing : " + std::to_string(new_capacity));
    #endif
    // Create new data block
    T* new_data = (T*)malloc(sizeof(T) * new_capacity);
    std::memcpy(new_data, _data, _size * sizeof(T));
    free(_data);
    _data = new_data;
    _capacity = new_capacity;
}

template <typename T>
void Vector<T>::resizeUp() {
    resize((uint)_capacity << 1);
}

template <typename T>
void Vector<T>::resizeDown() {
    resize(_capacity >> 1);
}

// Utilities
template <typename T>
void Vector<T>::print() {
    std::cout << "DynamicArray:\n";
    for (int i = 0; i < _size; i++) {
        std::cout << i << " = " << _data[i] << "\n";
    }
}