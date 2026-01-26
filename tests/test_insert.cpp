#include <cassert>

#include "List.h"

int main() {
    List<int> first_list;
    for (int i = 9; i >= 0; i--) {
        first_list.insertAtFront(i);
    }
    for (int i = 0; i < 10; i++) {
        assert(first_list[i] == i);
    }
    return 0;
}