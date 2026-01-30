#include <stdexcept>

template <typename T>
const T& List<T>::operator[](unsigned index) const {
    ensure_not_empty();
    if (index >= size) {
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
void List<T>::pop_front() {
    ensure_not_empty();
    Node* tmp = head;
    head = head->next;
    if (size > 1) {
        head->before = nullptr;
    } else {
        tail = nullptr;
    }
    delete tmp;
    size--;
}

template <typename T>
void List<T>::pop_back() {
    ensure_not_empty();
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

template <typename T>
const T& List<T>::front() {
    ensure_not_empty();
    return head->data;
}

template <typename T>
const T& List<T>::back() {
    ensure_not_empty();
    return tail->data;    
}

// Being a const function, this is equivalent to
// void ensure_not_empty(const List* this). So inside
// the function this is const and you can only call
// other const member functions. That is why i
// set the empty() function to const also.
template <typename T>
void List<T>::ensure_not_empty() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
}