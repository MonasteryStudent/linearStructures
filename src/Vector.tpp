#include <stdexcept>

template <typename T>
Vector<T>::Vector(const Vector<T>& other) 
    : data(nullptr), size(other.get_size()), capacity(other.get_capacity())
{
    if (capacity == 0) {
        return; // nothing to allocate
    }

    /* 
    For educational reasons:
    The simpler version of memory allocation would be to use the
    following syntax: 
        data = new T[capacity];
    This is simple and safe, but it goes with the disadvantage to
    construct capacity objects, even if size is smaller, e.g.
    capacity = 100 and size = 3. This would be inefficient for heavy
    objects.
    In contrast with the operator new + placement new syntax we just
    allocate raw memory for our capacity and manually construct only
    the objects that we need (i.e. size objects). Later on we
    also must manually destroy them, what happens with the code 
    in the destructor.
    */
    
    data = static_cast<T*>(::operator new(sizeof(T) * capacity));
    for (std::size_t i = 0; i < size; i++) {
        new (data + i) T(other[i]);
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) return *this;

    // destroy current contents
    for (std::size_t i = 0; i < size; i++) {
        data[i].~T();
    }
    ::operator delete(data);

    // copy sizes
    size = other.get_size();
    capacity = other.get_capacity();

    // allocate new raw memory
    data = static_cast<T*>(::operator new(sizeof(T) * capacity));

    // copy-construct elements into our raw memory
    for (std::size_t i = 0; i < size; i++) {
        new (data + i) T(other[i]);
    }

    return *this;

}


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

template <typename T>
const T& Vector<T>::front() {
    if (!size) {
        throw std::out_of_range("Vector is empty");
    }
    return data[0];
}