#include <cassert>
#include "List.h"

int main() {
    List<std::string> characters;
    const std::size_t size = 3;
    std::string new_characters[size] = {
        "Hofrat Dr.Behrens", 
        "Dr. Krokowski", 
        "Leo Naptha"
    };
    for (std::string character : new_characters) {
        characters.push_front(character);
    }
    assert(characters.back() == new_characters[0]);
    return 0;
}