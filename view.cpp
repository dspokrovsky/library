#if defined(_MSC_VER) || \
defined(__WIN32) || \
defined(__WIN32__) || \
defined(_WIN32) || \
defined(WIN32) || \
defined(__WINNT) || \
defined(__WINNT__) || \
defined(__WINNT)
//Винда
    #define OS "clc"
#else
    #define OS "clear"
//юних
#endif



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
    std::cout << "\nMenu: \n\n";
    std::cout << "list of books: 1\n";
    std::cout << "list of visitors: 2\n";
    std::cout << "give a book: 3\n";
    std::cout << "take a book: 4\n";
    std::cout << "list of debtors: 5\n\n";
    std::cout << "log out: 6\n\n";
    std::cout << "* Use new line to input a number, a book & an author \n";
    std::cout << "** Don't be rush, input carefully \n\n";
}

void view::update(int c){
    system(OS);
    switch(c){
        case 1:
            std::cout << "\n List of books: \n\n";
            for(auto it: model_->books()){
                std::cout << it <<std::endl;
            }
            break;
        case 2:
            std::cout << "\n List of visitors: \n\n";
            for(auto it: model_->visitors()){
                std::cout << it <<std::endl;
            }
            break;
        case 3:
            std::cout << "\n Success in the operation give a book.\n\n";
            break;
        case 31:
            std::cout << "\n Failure in the operation give a book.\n\n";
            break;
        case 4:
            std::cout << "\n Success == take a book \n\n";
            break;
        case 41:
            std::cout << "\n Failure == take a book \n\n";
            break;
        case 5:
            std::cout << "\n list of debtors: \n\n";
            for (auto i: model_->debtors()){
                std::cout << i <<std::endl;
            }
            break;
        case 6:
            exit(1);
            break;
        case 101:
            std::cout << "\n Enter the name of auther\n";
        break;
        case 100:
            std::cout << model_->lastEvent() <<std::endl;
            break;
        default:
            break;
    }
    this->menu();
}
