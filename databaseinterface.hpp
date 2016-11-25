#ifndef DATABASEINTERFACE_HPP
#define DATABASEINTERFACE_HPP

#include <visitor.h>
#include <book.h>
#include <vector>

class dataBaseInterface
{
public:
    virtual std::vector<visitor>& visitors() = 0;
    virtual std::vector<book>& books() = 0;
};

class dataBaseInterface1: public dataBaseInterface
{
public:
    dataBaseInterface1(std::vector<visitor> &_vis,std::vector<book> &_bo):visitors_(_vis), books_(_bo){
    }
    ~dataBaseInterface1(){
    }
    virtual std::vector<visitor>& visitors(){
        return visitors_;
    }
    virtual std::vector<book>& books(){
        return books_;
    }
    std::vector<book> books_;
    std::vector<visitor> visitors_;
};

class dataBaseInterface2: public dataBaseInterface
{
public:
    dataBaseInterface2(std::vector<std::string> &_vis,std::vector<std::string> &_bo){
        for(auto i: _vis){
            visitors_.push_back(visitor(i));
        }
        for(auto i: _bo){
            books_.push_back(book(i));
        }
    }
    ~dataBaseInterface2(){
        std::cout << "D2 died\n";
    }
    virtual std::vector<visitor>& visitors(){
        return visitors_;
    }
    virtual std::vector<book>& books(){
        return books_;
    }
    std::vector<book> books_;
    std::vector<visitor> visitors_;
};




#endif // DATABASEINTERFACE_HPP
