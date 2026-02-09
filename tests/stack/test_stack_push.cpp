#include <cassert>
#include <cstddef>

#include "Stack.h"

int main() {
    Stack<int> fibonacci_seq;
    const std::size_t size = 8;
    int new_elements[size] = {0, 1, 1, 2, 3, 5, 8, 13};
    assert(0 == fibonacci_seq.get_size());
    for (std::size_t index = 0; index < size; index++) {
        fibonacci_seq.push(new_elements[index]);
        assert(new_elements[index] == fibonacci_seq.top());
    }
    assert(size == fibonacci_seq.get_size());
}