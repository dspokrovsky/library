#ifndef VISITOR_H
#define VISITOR_H
#include <string>
#include <book.h>


class visitor
{    
public:
    const std::string& name() const{
        return name_;
    }
    std::string& name(){
        return name_;
    }



private:
    std::string name_;
    book* book_;
};

#endif // VISITOR_H
