#include <cassert>
#include <cstddef>

#include "Queue.h"

int main() {
    Queue<std::string> superheros;
    const std::size_t size = 4;
    std::string invincible_heros[size] = {
        "Invincible",
        "Omni-Man",
        "Atom Eve",
        "Allen the Alien"
    };
    for (std::string hero : invincible_heros) { 
        superheros.push(hero);
    }
    for (std::size_t index = 0; index < size; index++) {
        assert(invincible_heros[index] == superheros.front());
        superheros.pop();
    }
    return 0;
}