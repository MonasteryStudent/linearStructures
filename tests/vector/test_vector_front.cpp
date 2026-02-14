#include <cassert>
#include <stdexcept>

#include "test_utils.h"
#include "Vector.h"

int main() {
    Vector<char> letters;
    letters.push_back('a');
    assert('a' == letters.front());
    letters.push_back('b');
    assert('a' == letters.front() && 'b' != letters.front());
    letters.pop_back();
    letters.pop_back();

    assert_throw<std::out_of_range>([&] { letters.pop_back(); });
}
