#ifndef CONTROLER_H
#define CONTROLER_H
#include <model.h>
#include <iostream>
#include <cstdlib>


class controler
{
public:
    explicit controler(model *_m){
        model_ = _m;
    }

    void start();
    /*{
        std::string str_b;
        std::string str_b2;
        visitor vi_b(str_b);
        book bo_b(str_b2);
        model_->notifyUpdate(0);
        int _b=-2;
        char ch;
        do{
            //ch = std::cin.get();
            std::cin >> ch;
            _b = std::atoi(&ch);
            //std::cin.ignore();
            //std::cin.flush();
            switch(_b){
            case -2:
                break;
            case 0:
                model_->donoth(_b);
                break;
            case 1:
                model_->books(_b);
                break;
            case 2:
                model_->visitors(_b);
                break;
            case 3:

                getline(std::cin, str_b);
                vi_b.name() = str_b;
                getline(std::cin, str_b2);
                bo_b.name() = str_b2;
                model_->recieveBook(vi_b,bo_b,_b);
                break;
            case 4:
                getline(std::cin, str_b);
                vi_b.name() = str_b;
                getline(std::cin, str_b2);
                bo_b.name() = str_b2;
                model_->returnBook(vi_b,bo_b,_b);
                break;
            case 5:
                model_->updateDebtors(_b);
                break;
            case 6:
                exit(1);
                break;
            default:
                model_->donoth(_b);
                break;
            };
        }while(_b != -1);
    }*/

private:
    model *model_;

};

#endif // CONTROLER_H
