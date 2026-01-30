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
    assert(superheros.get_size() == 0);
    for (std::string hero : invincible_heros) { superheros.push(hero); }
    assert(superheros.get_size() == size);
    return 0;
}