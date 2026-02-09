#include <cassert>
#include <stdexcept>

#include "test_utils.h"
#include "Vector.h"

int main() {

    Vector<int> primes;
    
    const std::size_t size = 5;
    int new_primes[size] = {2, 3, 5, 7, 11};
    for (int prime : new_primes) {
        primes.push_back(prime);
    }
    assert(size == primes.get_size());
    while (primes.get_size()) {
        primes.pop_back();
    }
    assert(0 == primes.get_size());
    
    assert_throw<std::out_of_range>([&] { primes.pop_back(); });

}

