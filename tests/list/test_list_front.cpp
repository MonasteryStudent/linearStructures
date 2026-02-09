#include <cassert> 
#include "List.h"

int main() {
    List<std::string> book_titles;
    std::string new_book = "Die Geschichten Jakobs";
    book_titles.push_front(new_book);
    assert(book_titles.front() == new_book);
    return 0;
}