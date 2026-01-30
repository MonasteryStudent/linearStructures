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

    // Return true if the list is empty.
    bool empty() const { return size == 0; };

    std::size_t get_size() { return size; };

    // A reference is an alias - another name for an existing object.
    // The paramenter "const T& data" means, alias to the value, but read-only.
    // This is the same const-correctness as above. With this i can express 
    // the intended behaviour of the function with references.
    void push_front(const T& data);

    // Removes the tail node of the list.
    void pop_front();

    // Removes the head node of the list.
    void pop_back();

    // Returns the data of the head node.
    const T& front();

    // Returns the data of the tail node.
    const T& back();

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
    std::size_t size;

    void ensure_not_empty() const;
};

#include "List.tpp"