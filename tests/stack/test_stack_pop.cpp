#include <cassert>
#include <stdexcept>

#include "Stack.h"
#include "test_utils.h"

int main() {
    Stack<int> fibonacci_seq;
    const std::size_t size = 8;
    int new_elements[size] = {0, 1, 1, 2, 3, 5, 8, 13};
    assert(0 == fibonacci_seq.get_size());
    for (int elem : new_elements) {
        fibonacci_seq.push(elem);
    }
    assert(size == fibonacci_seq.get_size());
    std::size_t index = size - 1;
    while (!fibonacci_seq.empty()) {
        assert(new_elements[index] == fibonacci_seq.top());
        fibonacci_seq.pop();
        index--;
    }
    assert(0 == fibonacci_seq.get_size());
    assert_throw<std::out_of_range>([&] { fibonacci_seq.pop(); });
}