#include <iostream>
#include <view.h>
#include <model.h>
#include <controler.h>
#include <book.h>
#include <visitor.h>
#include <utility>
#include <ctime>

int main()
{
    // fill the model;
    std::vector <book> b  = {book("Fahrenheit 451"),book("The Martian Chronicles"),book("Green Town")};
    std::vector <visitor> v = {visitor("Ilya Vesel"),visitor("Jon Snow"), visitor("Dave")};

    model mod(v,b);

    //user recieve a book
    mod.recieveBook(v[0],b[2],0);
    // set time of this book in UNIX for testing our time
    mod.books()[2].t() =100;

    view ui(&mod);
    controler contr(&mod);
    contr.start();
    return 0;
}
