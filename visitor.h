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
    visitor(const visitor& _m )
        :name_{_m.name()}
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
    int size(){
        return books_.size();
    }
    int size()const{
        return books_.size();
    }
    std::vector<book*>& books(){
        return books_;
    }
    void addBook(book* ptr){
        ptr->own() =1;
        ptr->t() = std::time(0);
        books_.push_back(ptr);
    }

private:
    std::string name_;
    std::vector<book*> books_;
};
#endif // VISITOR_H
