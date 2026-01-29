#include <stdexcept>

template <typename T>
const T& List<T>::operator[](unsigned index) const {
    if (!head) {
        throw std::out_of_range("List is empty");
    } else if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    Node* cursor = head;

    while (index > 0 && cursor->next != nullptr) {
        cursor = cursor -> next;
        index--;
    }
    return cursor->data;
}

template <typename T>
void List<T>::push_front(const T& data) {
    Node* node = new Node(data);
    node->next = head;
    if (!head) { 
        tail = node; 
    } else {
        head->before = node;
    }
    
    head = node;
    size++;
}

template <typename T>
void List<T>::pop_back() {
    if (!size) {
        throw std::out_of_range("List is empty");
    }
    Node* tmp = tail;
    tail = tail->before;
    if (size == 1) {
        head = nullptr;
    } else {
        tail->next = nullptr;
    }
    delete tmp;
    size--;
}