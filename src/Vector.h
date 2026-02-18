#pragma once

#include <cstddef> // to use std::size_t

template <typename T>
class Vector {
public:

    Vector() : data(nullptr), size(0), capacity(0) {}
    // copy constructor
    Vector(const Vector<T>& other);
    ~Vector() {
        for (std::size_t i = 0; i < size; i++) {
            data[i].~T(); // destroy the current objects
        }
        ::operator delete(data); // free memory
    }
    // Copy assignment operator
    Vector<T>& operator=(const Vector<T>& other);

    // Pass small, trivially copyable types by value,
    // because this functin doesn't care about the identity
    // or lifetime of the index argument.
    // We also don't add const to the index, because
    // modifying it would not affect the caller and
    // we have no reason to alter the index.
    const T& operator[](std::size_t index) const;
    T& operator[](std::size_t index); // returns modifiable reference
    void push_back(const T& value);
    void pop_back();
    const T& front();

    // A const member function can still be called on
    // non-const objects. That's why we can simplify
    // the getters to only const versions. Think of it like,
    // if something is safe for a const obj, it is also safe
    // for a non-const obj.
    std::size_t get_size() const { return size; } 
    std::size_t get_capacity() const { return capacity; }

private:
    T* data;
    std::size_t size, capacity;
};

#include "Vector.tpp"