#include <cassert>
#include <stdexcept>

#include "test_utils.h"
#include "List.h"

int main() {

    List<int> primes;

    const std::size_t size = 5;
    int new_primes[size] = {2, 3, 5, 7, 11};
    for (int prime : new_primes) {
        primes.push_front(prime);
    
    }
    assert(size == primes.get_size());
    while (!primes.empty()) {
        primes.pop_back();
    }
    assert(0 == primes.get_size());
    
    // The lambda expression down below is an anonymous function object that we can define inline. 
    // It captures the object and calls the member function.
    // To make it clear: The lambda [&] { primes.pop_back(); } is an rvalue temporary,
    // so the Func&& func binds to it as a forwarding reference.
    // Inside asser_throw, calling func() executes the lambda.
    assert_throw<std::out_of_range>([&] { primes.pop_back(); });

    return 0;
}