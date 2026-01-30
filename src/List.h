#pragma once

#include <cstddef> // to use std::size_t

template <typename T>
class List {
public:
    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    // The const at the end of the function signature
    // means that this function promises not to modify
    // the list. It's also called const-correctness.
    const T& operator[](unsigned index) const;
    bool empty() { return size == 0; };
    std::size_t get_size() { return size; };
    // A reference is an alias - another name for an existing object.
    // The paramenter "const T& data" means, alias to the value, but read-only.
    // This is the same const-correctness as above. With this i can express 
    // the intended behaviour of the function with references.
    void push_front(const T& data);
    void pop_back();
    const T& back();
    
    std::size_t size;

private:
    class Node {
    public:
        T data;
        Node* next;
        Node* before;
        // The explicit keyword prevents implicit conversions.
        explicit Node(const T& data) : data(data), next(nullptr), before(nullptr) {}
    };

    Node* head;
    Node* tail;
};

#include "List.tpp"