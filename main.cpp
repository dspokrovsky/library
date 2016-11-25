#include <iostream>
#include <view.h>
#include <model.h>
#include <controler.h>
#include <book.h>
#include <visitor.h>
#include <utility>
#include <ctime>
#include <databaseinterface.hpp>

int main()
{
    // fill the model;
    std::vector <book> b  = {book("Fahrenheit 451"),book("The Martian Chronicles"),book("Green Town")};
    std::vector <visitor> v = {visitor("Ilya Vesel"),visitor("Jon Snow"), visitor("Dave")};
    //second
    std::vector <std::string> b2 = {"Fahrenheit 451","a","aa","bb","cc"};
    std::vector <std::string> v2 = {"qwer"};



    std::cout << " CHOSE DATABASE: 1 2 3 "<<std::endl;
    std::shared_ptr<dataBaseInterface> p;
    int c;
    std::cin >>c;
    dataBaseInterface1 D(v,b);
    std::shared_ptr<dataBaseInterface1> ptr = std::make_shared<dataBaseInterface1>(D);
    dataBaseInterface2 D2(v2,b2);
    std::shared_ptr<dataBaseInterface2> ptr2 = std::make_shared<dataBaseInterface2>(D2);
    switch(c){
        case 1:
            p = ptr;
            break;
        case 2:
            p = ptr2;
            break;
        case 3:

            break;

        default:
            break;
    }


    model mod(p);

    //user recieve a book
    mod.recieveBook(v[0],b[2],0);
    // set time of this book in UNIX for testing our time
    mod.books()[2].t() =100;

    view ui(&mod);
    controler contr(&mod);
    contr.start();
    return 0;
}
