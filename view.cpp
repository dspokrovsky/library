#define OS "cls"
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include "view.h"
#include <algorithm>

view::view(model *_m){
    model_ = _m;
    model_->addObserver(this);
}

void view::menu(){
    system(OS);
    std::cout << "Menu: \n\n";
    std::cout << "list of books: 1\n";
    std::cout << "list of visitors: 2\n";
    std::cout << "give a book: 3\n";
    std::cout << "take a book: 4\n";
    std::cout << "list of debtors: 5\n\n";
    std::cout << "log out: 6\n\n";
    std::cout << "* Use new line to input a number, a book & an author \n\n";
}

void view::update(int c){
    system(OS);
    switch(c){
        case 0:
            this->menu();
            break;
        case 1:
            std::cout << "\nlist of books: \n\n";
            for(auto it: model_->books()){
                std::cout << it <<std::endl;
            }
            std::cout << "\ntry again: 0\n";
            std::cout << "log out: 6";
            break;
        case 2:
            std::cout << "\nlist of visitors: \n\n";
            for(auto it: model_->visitors()){
                std::cout << it <<std::endl;
            }
            std::cout << "\ntry again: 0\n";
            std::cout << "log out: 6";
            break;
        case 3:

            std::cout << "\nSuccess in the operation give a book.\n\n";
            std::cout << "\ntry again: 0\n";
            std::cout << "log out: 6\n";
            break;
        case 31:
            std::cout << "\nFailure in the operation give a book.\n\n";
            std::cout << "\ntry again: 0\n";
            std::cout << "log out: 6";
            break;
        case 4:
            std::cout << "\n Success == take a book \n\n";
            std::cout << "\ntry again: 0\n";
            std::cout << "log out: 6";
            break;
        case 41:

            std::cout << "\n Failure == take a book \n\n";
            std::cout << "\ntry again: 0\n";
            std::cout << "log out: 6";
        break;

        case 5:
            std::cout << "\nlist of debtors: \n\n";
            for (auto i: model_->debtors()){
                std::cout << i <<std::endl;
            }
            std::cout << "\ntry again: 0\n";
            std::cout << "log out: 6";
            break;
        case 6:
            exit(1);
            break;
        default:
            std::cout << "\ntry again: 0\n";
            std::cout << "log out: 6\n";
            break;
    }
}
