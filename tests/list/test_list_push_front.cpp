#include <cassert>

#include "List.h"

int main() {
    List<std::string> characters;
    std::string new_characters[3] = {
        "Hofrat Dr.Behrens", 
        "Dr. Krokowski", 
        "Leo Naptha"
    };
    int index = 0;
    for (std::string character : new_characters) {
        characters.push_front(character);
        assert(characters[0] == new_characters[index]);
        index++;
    }
    return 0;
}