#include <cassert>

#include "Vector.h"

int main() {
    Vector<int> first_vector;
    for (int i = 0; i < 10; i++) {
        first_vector.push_back(i);
        assert(first_vector[i] == i);
    }
}