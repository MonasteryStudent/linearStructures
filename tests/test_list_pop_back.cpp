#include <cassert>
#include <stdexcept>

#include <List.h>

int main() {

    List<int> primes;
    
    const std::size_t size = 5;
    int new_primes[size] = {2, 3, 5, 7, 11};
    for (int prime : new_primes) {
        primes.push_front(prime);
    
    }
    assert(size == primes.get_size());
    while (!primes.is_empty()) {
        primes.pop_back();
    }
    assert(0 == primes.get_size());
    
    bool exception_thrown = false;
    try {
        primes.pop_back();
    } catch (const std::out_of_range&) {
        exception_thrown = true;
    }
    assert(exception_thrown);
    
    return 0;
}