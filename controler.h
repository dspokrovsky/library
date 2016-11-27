#ifndef CONTROLER_H
#define CONTROLER_H
#include "model.h"
#include <iostream>
#include <cstdlib>


class controler
{
public:
    explicit controler(model *_m){
        model_ = _m;
    }

    int start();

private:
    model *model_;

};

#endif // CONTROLER_H
