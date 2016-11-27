#include "model.h"
#include <fstream>
#include <algorithm>
//constructos
model::model(storageVisitor_t &vsts, storageBook_t &bks):visitors_(vsts),books_(bks){}
model::model(std::shared_ptr<dataBaseInterface> _d):visitors_(_d->visitors()),books_(_d->books()), storeOurData(_d){}
model::~model() {/*
	if (storeOurData != nullptr) {
		storeOurData->save(visitors(),books());
		storeOurData = nullptr;
	}*/
}
//accessors
model::storageVisitor_t& model::visitors(int c){
    notifyUpdate(c);
    return visitors_;
}
model::storageVisitor_t& model::visitors(){
    return visitors_;
}
const model::storageVisitor_t& model::visitors() const{
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
const std::string& model::lastEvent(){
    return lastEvent_;
}

//
void model::addBook(book bk, int c){
    books().push_back(bk);
    notifyUpdate(c);
}
void model::addVisitor(visitor vt, int c){
    visitors().push_back(vt);
    notifyUpdate(c);
}
//businesslogic
int model::recieveBook(const visitor &vt,const book &bk,int c){
    auto it = std::find(visitors().begin(),visitors().end(),vt);
    if(it == visitors().end()) {
        lastEvent_ = "ERROR no visitor: " + vt.name();
        notifyUpdate(100);
        return -1;
    }
    auto it2 = std::find(books().begin(),books().end(),bk);
    if ( it2 == books().end()){
        lastEvent_ = "ERROR no book: " + bk.name();
        notifyUpdate(100);
        return -1;
    }
    if(it2->t()!=0){
        lastEvent_ = "ERROR This book in the possession of another user " ;
        notifyUpdate(100);
        return -1;
    }
    if (it->size() >=3){
        lastEvent_ = "ERROR U have 3 books" ;
        notifyUpdate(100);
        return -1;
    }
    (*it).addBook(&(*it2));
    notifyUpdate(c);
    return 1;
}
int model::returnBook(visitor vt,book bk,int c){
    auto it = std::find(visitors().begin(),visitors().end(),vt);
    //for_each(visitors().begin(),visitors().end(),[](visitor i){std::cout << i.name() <<std::endl;}); // degug
    if(it == visitors().end()){
        lastEvent_ = "ERROR no visitor: " + vt.name();
        notifyUpdate(100);
        return -1;
    }
    for(auto it2 = it->books().begin(); it2 != it->books().end(); it2++){
        if (bk.name() == (*it2)->name()){
            it->books().erase(it2);
            notifyUpdate(c);
            return 1;
        }
    }
    lastEvent_ = "ERROR no book: " + bk.name();
    notifyUpdate(100);
    return -1;
}
int model::updateDebtors(int c){
    std::vector<std::string> debts;
    for(auto it = visitors().begin(); it != visitors().end(); it++){
        for (auto it2 = it->books().begin(); it2 != it->books().end();it2++){
            if ( ((*it2)->t() + 2592000 )< std::time(0)){
                debts.push_back((*it).name());
            }
        }
    }
    debtors_ = debts;
    notifyUpdate(c);
    return 1;
}
const std::vector<std::string>& model::debtors() const{
    return debtors_;
}
//
void model::sentUpdateToView(int c){
    notifyUpdate(c);
}
