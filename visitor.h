#ifndef VISITOR_H
#define VISITOR_H
#include <string>
#include <vector>
#include <book.h>
#include <ostream>

class visitor
{    
public:
    visitor(std::string _m )
        :name_{_m}
    {}

    const std::string& name() const{
        return name_;
    }
    std::string& name(){
        return name_;
    }
    friend bool operator< (const visitor &oth1,const visitor &oth2){
        return oth1.name() < oth2.name();
    }
    friend bool operator== (const visitor &oth1,const visitor &oth2){
        return oth1.name() == oth2.name();
    }
    friend std::ostream &operator<<(std::ostream &os, const visitor &obj){
        os << obj.name();
        return os;
    }
    int& size(){
        return size_;
    }

private:
    std::string name_;
    int size_ = 0;
};
#endif // VISITOR_H
