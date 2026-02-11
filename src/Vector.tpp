#include <stdexcept>

template <typename T>
const T& Vector<T>::operator[](std::size_t index) const {
    if (!size) {
        throw std::out_of_range("Vector is empty");
    } else if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }
    return data[index];
};

template <typename T>
T& Vector<T>::operator[](std::size_t index) {
    if (!size) {
        throw std::out_of_range("Vector is empty");
    } else if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }
    return data[index];   
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    // resize
    if (size == capacity) {
        std::size_t new_capacity = (capacity == 0) ? 2 : capacity * 2;
        // Allocate raw memory and construct nothing.
        T* new_data = static_cast<T*>(::operator new(sizeof(T) * new_capacity));
        
        for (std::size_t i = 0; i < size; i++) {
            // Explicitly construct objects.
            // (new_data + i) is the memory address where we
            // contruct the object with T(data[i]).
            new (new_data + i) T(data[i]); // placement new
            // End the lifetime of the object at data[i], but
            // it doesn't free memory. It just calls the
            // destructor of the object with ~T. After the
            // call no T object lives there anymore.
            data[i].~T();
        }
        ::operator delete(data); // free memory
        data = new_data;
        capacity = new_capacity;
    }
    // construct new element
    new (data + size) T(value);
    ++size;
};


template <typename T>
void Vector<T>::pop_back() {
    if (!size) {
        throw std::out_of_range("Vector is empty");
    }
    data[--size].~T();
}
