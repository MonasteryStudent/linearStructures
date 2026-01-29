#pragma once
#include <cstddef>

template <typename T>
class Vector {
public:
    Vector() : data(nullptr), size(0), capacity(0) {}
    ~Vector() {
        for (std::size_t i = 0; i < size; i++) {
            data[i].~T(); // destroy the current objects
        }
        ::operator delete(data); // free memory
    }

    // Pass small, trivially copyable types by value,
    // because this functin doesn't care about the identity
    // or lifetime of the index argument.
    // We also don't add const to the index, because
    // modifying it would not affect the caller and
    // we have no reason to alter the index.
    const T& operator[](std::size_t index) const;
    void push_back(const T& value);
    void pop_back();
    std::size_t get_size() { return size; }

private:
    T* data;
    std::size_t size, capacity;
};

#include "Vector.tpp"