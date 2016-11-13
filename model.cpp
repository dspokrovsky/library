#include "model.h"
#include <fstream>
#include <algorithm>
model::model()
{

}
model::model(std::string data)
{
    std::fstream ff(data);
    int size;
    ff >> size;
    for(int i =0; i < size; i++){
        /*std::vector <std::string > buf[6];
        for_each(buf.begin(),buf.end(), [](std::string _n){
            visitors().insert();
        });*/


    }
}

