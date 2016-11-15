#include "model.h"
#include <fstream>
#include <algorithm>
model::model(storage_t vsts, storageBook_t bks):visitors_(vsts),books_(bks)
{

}


model::storage_t& model::visitors(int c){
    notifyUpdate(c);
    return visitors_;
}
model::storage_t& model::visitors(){
    return visitors_;
}
const model::storage_t& model::visitors() const{
    return visitors_;
}
std::vector<book>& model::books(){
    return books_;
}
std::vector<book>& model::books(int c){
    this->notifyUpdate(c);
    return books_;
}
const std::vector<book>& model::books() const{
    return books_;
}
void model::addBook(book bk, int c){
    books().push_back(bk);
    notifyUpdate(c);
}
void model::addVisitor(visitor vt, int c){
    visitors().push_back(vt);
    notifyUpdate(c);
}
int model::recieveBook(visitor vt,book bk,int c){
    auto it = std::find(visitors().begin(),visitors().end(),vt);
    if(it == visitors().end()) {
        notifyUpdate(31);
        return -1;
    }
    auto it2 = std::find(books().begin(),books().end(),bk);
    if(it2 == books().end()) {
        notifyUpdate(31);
        return -1;
    }
    if (it->size() >=3){
        notifyUpdate(31);
        return -1;
    }
    (*it).addBook(&(*it2));
    notifyUpdate(c);
    return 1;
}

int model::returnBook(visitor vt,book bk,int c){
    auto it = std::find(visitors().begin(),visitors().end(),vt);
    if(it == visitors().end()){
        notifyUpdate(41);
        return -1;
    }
    for(auto it2 = it->books().begin(); it2 != it->books().end(); it++){
        if (bk.name() == (*it2)->name()){
            it->books().erase(it2);
            notifyUpdate(c);
            return 1;
        }
    }
    notifyUpdate(41);
    return -1;

}
int model::updateDebtors(int c){
    std::vector<visitor> debts;
    for(auto it = visitors().begin(); it != visitors().end(); it++){
        for (auto it2 = it->books().begin(); it2 != it->books().end();it2++){
            if ( ((*it2)->t() + 2592000 )< std::time(0)){
                debts.push_back(*it);
            }
        }
    }
    debtors_ = debts;
    return 1;
}

std::vector<visitor>& model::debtors(){
    return debtors_;
}

void model::donoth(int c){
    notifyUpdate(c);
}
