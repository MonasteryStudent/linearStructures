#pragma once

#include "List.h"

template <typename T>
class Queue {
public:

    // Calls default constructor of the list class.
    // A default constructor is any constructor that 
    // can be called with no arguments.
    Queue() = default;

    // Adds data to the back of the queue.
    void push(const T& data) { list.push_front(data); };

    // Removes data from the front the queue.
    void pop() { list.pop_back(); };

    // Returns true if the queue is emtpy
    bool empty() { list.emtpy() };

private:
    List<T> list;
};
