#include <cassert>

#include "Vector.h"

int main() {
    Vector<std::string> characters;
    std::string new_characters[3] = {
        "Hans Castorp", 
        "Joachim Ziemßen", 
        "Lodovico Settembrini"
    };
    int index = 0;
    for (std::string character : new_characters) {
        characters.push_back(character);
        assert(characters[index] == new_characters[index]);
        index++;
    }
    return 0;
}