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
    system("cls");
    std::cout << "Menu: \n";
    std::cout << "list of books: 1\n";
    std::cout << "list of visitors: 2\n";
    std::cout << "give a book: 3\n";
    std::cout << "take a book: 4\n";
    std::cout << "list of debtors: 5\n";
    std::cout << "log out: 6\n";
}

void view::update(int c){
    system("cls");
    switch(c){
        case 0:
            this->menu();
            break;
        case 1:
            std::cout << "list of books: \n";
            for(auto it: model_->books()){
                std::cout << it <<std::endl;
            }
            std::cout << "try again: 0\n";
            std::cout << "log out: 6";
            break;
        case 2:
            std::cout << "list of visitors: \n";
            for(auto it: model_->visitors()){
                //std::cout << it.first <<std::endl;
                std::cout << it <<std::endl;
            }
            std::cout << "try again: 0\n";
            std::cout << "log out: 6";
            break;
        case 3:

            std::cout << "give a book: 3\n";
            std::cout << "try again: 0\n";
            std::cout << "log out: 6";
            break;
        case 4:
            std::cout << "take a book: 4\n";
            std::cout << "try again: 0\n";
            std::cout << "log out: 6";
            break;
        case 5:
            std::cout << "list of debtors: 5\n";
            std::cout << "try again: 0\n";
            std::cout << "log out: 6";
            break;
        case 6:
            exit(1);
            break;
        default:
            std::cout << "try again: 0\n";
            std::cout << "log out: 6\n";
            break;
    }
}
