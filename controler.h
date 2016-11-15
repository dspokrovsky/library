#ifndef CONTROLER_H
#define CONTROLER_H
#include <model.h>
#include <iostream>


class controler
{
public:
    explicit controler(model *_m){
        model_ = _m;
    }

    int start(){
        std::string str_b("aaa");
        std::string str_b2("aaa");
        visitor vi_b(str_b);
        book bo_b(str_b2);
        model_->notifyUpdate(0);
        int _b;
        do{
            try{
                scanf("%d",&_b);
            }catch(...){
                model_->donoth(0);
                throw;
            }
            switch(_b){
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

                //scanf("%s",str_b);
                vi_b.name() = str_b;

                //scanf("%s",str_b2);
                bo_b.name() = str_b2;
                model_->recieveBook(vi_b,bo_b,_b);
                break;
            case 6:
                exit(1);
                break;
            default:
                model_->donoth(0);
                break;
            };
        }while(_b != -1);
    }

private:
    model *model_;

};

#endif // CONTROLER_H
