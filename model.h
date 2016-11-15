#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <visitor.h>
#include <book.h>
#include <ctime>
#include <vector>
#include <observer.h>
#include <utility>


namespace  detail {
    struct visData_t{
        book *booksPtr_ = nullptr;
        std::time_t debtTime_ = 0;
    };
}


class model: public observable
{

public:
    using storage_t = std::map< visitor, std::vector<detail::visData_t> >;
    using storageBook_t = std::vector<book>;
    model();
    explicit model(std::string data);
    // accessors

    storage_t& visitors(int c){
        notifyUpdate(c);
        return visitors_;
    }
    storage_t& visitors(){
        return visitors_;
    }
    const storage_t& visitors() const{
        return visitors_;
    }
    std::vector<book>& books(){
        return books_;
    }
    std::vector<book>& books(int c){
        this->notifyUpdate(c);
        return books_;
    }
    const std::vector<book>& books() const{
        return books_;
    }
    void addBook(book bk, int c){
        books().push_back(bk);
        notifyUpdate(c);
    }
    void addVisitor(visitor vt, int c){
        std::vector <detail::visData_t> k;
        visitors().emplace(std::make_pair(vt,k));
        notifyUpdate(c);
    }
    void giveBook(visitor vt,book *bk,int c){
        if (vt.size() <3){
            detail::visData_t buf;
            buf.booksPtr_ = bk;
            buf.debtTime_ = std::time(nullptr);
            this->visitors().find(vt)->second.push_back(buf);
        }
        notifyUpdate(c);
    }

    void donoth(int c){
        notifyUpdate(c);
    }

    /*
    std::vector<visitor> debtVisitors(int c){

        std::vector<visitor> debt;
        for(auto it =  this->visitors().begin(); it != this->visitors().end(); ++it){
            if(it->second.debtTime_ + 2592000 > std::time()){
                debt.push_back(it->first);
            }
        }
        notifyUpdate(c);
        return debt;
    }*/

private:
    storage_t visitors_;
    storageBook_t books_;
};

#endif // MODEL_H
