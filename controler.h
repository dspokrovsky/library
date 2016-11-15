#ifndef CONTROLER_H
#define CONTROLER_H
#include <model.h>

class controler
{
public:
    explicit controler(model *_m){
        model_ = _m;
    }

    int start(){
        model_->notifyUpdate(0);
        int _b;
        do{
            scanf("%d",&_b);
            switch(_b){
            case 0:{
                model_->donoth(_b);
                break;}
            case 1:
                model_->books(_b);
                break;
            case 2:
                model_->visitors(_b);
                break;
            case 3:
                //std::
                //scanf()

                break;
            case 4:
                //std::cout << "take a book: 4\n";
                break;
            case 5:
//                std::cout << "list of debtors: 5\n";

                break;
            case 6:
                exit(1);
                break;
            default:
                break;
            };
        }while(_b != -1);
    }

private:
    model *model_;

};

#endif // CONTROLER_H
