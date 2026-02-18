#include <cassert>
#include <cstddef>
#include "Vector.h"

int main() {
    Vector<std::string> original;
    original.push_back("Superman");
    original.push_back("Batman");
    original.push_back("Spider-Man");
    original.push_back("Captain America");
    original.push_back("Wonder Woman");
    // run the copy constructor
    Vector<std::string> copy(original);
    // or Vector<std::string> copy(original) = original;
    for (std::size_t i = 0; i < original.get_size(); i++) {
        assert(original[i] == copy[i]);
    }    
}