#include "consoleui.h"
#include <stdlib.h>

int consoleUi::menu(){
    system("cls");
    std::cout << "list of books: 1\n";
    std::cout << "list of visitors: 2\n";
    std::cout << "give a book: 3\n";
    std::cout << "take a book: 4\n";
    std::cout << "list of debtors: 5\n";
    return 0;
}
