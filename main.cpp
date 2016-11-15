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
    model mod;
    book b1("programming C++");
    book b2("learn how to learn");
    mod.books().push_back(b1);
    mod.books().push_back(b2);
    visitor v1("vasya pupkin");
    visitor v2("vasya pupkin 2");
    //time_t t1 = std::time();
    std::vector <detail::visData_t> l;
    //std::vector <detail::visData_t> l2 = {}
    mod.visitors().emplace(std::make_pair(v1,l));
    view ui(&mod);
    controler contr(&mod);
    contr.start();
    return 0;
}
