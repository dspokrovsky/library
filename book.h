#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>
#include <ctime>

class book{

public:
    book(std::string _n): name_{_n}{}
    book(std::string _n, time_t _t): name_{_n}, t_{_t}{}

    const std::string& name() const{
        return name_;
    }
    std::string& name(){
        return name_;
    }
    friend bool operator< (const book &oth1,const book &oth2){
        return (oth1.name() < oth2.name());
    }
    friend bool operator== (const book &oth1,const book &oth2){
        return (oth1.name() == oth2.name());
    }
    friend std::ostream &operator<<(std::ostream &os, const book &obj){
        os << obj.name();
        return os;
    }
    int& own(){
        return own_;
    }
    std::time_t& t(){
        return t_;
    }
    bool debt(){
        return (own()==1 && ((t() + 256000) < std::time(nullptr)));
    }

private:
    std::string name_;
    int own_ = 0;
    std::time_t t_ =0;
};
#endif // BOOK_H
