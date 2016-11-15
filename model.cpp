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
    //std::vector <detail::visData_t> k;
    //visitors().emplace(std::make_pair(vt,k));
    visitors().push_back(vt);
    notifyUpdate(c);
}
int model::recieveBook(visitor vt,book bk,int c){
    auto it = std::find(visitors().begin(),visitors().end(),vt);
    if(it == visitors().end()) {
        notifyUpdate(0);
        return -1;
    }
    auto it2 = std::find(books().begin(),books().end(),bk);
    if(it2 == books().end()) {
        notifyUpdate(0);
        return -1;
    }
    if (it->size() >=3){
        notifyUpdate(0);
        return -1;
    }

    visitor buf(*it);
    buf.addBook(&(*it2));
    visitors().erase(it);
    visitors().push_back(buf);
    notifyUpdate(c);
}

void model::returnBook(visitor vt,book bk,int c){

}


void model::donoth(int c){
    notifyUpdate(c);
}
