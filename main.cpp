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
    book b1("programming C++");
    book b3("aaa");
    book b2("learn how to learn");
    visitor v1("vasya pupkin");
    visitor v2("aaa");
    //std::vector <detail::visData_t> l;
    model::storage_t vst;
    vst.push_back(v1);
    vst.push_back(v2);
    model::storageBook_t bks;
    bks.push_back(b1);
    bks.push_back(b2);
    bks.push_back(b3);

    model mod(vst,bks);

    view ui(&mod);
    controler contr(&mod);
    contr.start();
    return 0;
}
