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
    std::vector <book> b  = {book("Fahrenheit"),book("TheMartianChronicles "),book("GreenTown")};
    std::vector <visitor> v = {visitor("IlyaVesel"),visitor("JonSnow"), visitor("Dave")};

    model mod(v,b);
    view ui(&mod);
    controler contr(&mod);
    contr.start();
    return 0;
}
