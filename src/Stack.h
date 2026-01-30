#pragma once

#include <cstddef>
#include "List.h"

template <typename T>
class Stack {
public:
    Stack() = default;
    
    // Adds data to the top of the stack.
    void push(const T& data) { list.push_front(data); };

    // Removes data from the top of the stack.
    // void pop() { list.pop_front() };
    
    // Returns the data at the top of the stack.
    // const T& top() { list.front(); };

    // Returns true if the stack is empty
    bool empty() { list.empty(); };
    
    // Returns the size of the stack.
    std::size_t get_size() { list.get_size(); };


private:
    List<T> list;

};