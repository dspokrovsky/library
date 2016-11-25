#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <visitor.h>
#include <book.h>
#include <ctime>
#include <vector>
#include <observer.h>
#include <utility>
#include <databaseinterface.hpp>
#include <memory>

class model: public observable
{

public:
    //types
    using storageVisitor_t = std::vector< visitor >;
    using storageBook_t = std::vector<book>;
    //constr'es
    model(){}
    explicit model(std::shared_ptr<dataBaseInterface> _d);
    //old one co
    explicit model(storageVisitor_t &vsts, storageBook_t &bks);
    ~model(){}
    // accessors
    storageVisitor_t& visitors(int c);
    storageVisitor_t& visitors();
    const storageVisitor_t& visitors() const;
    std::vector<book>& books();
    std::vector<book>& books(int c);
    const std::vector<book>& books() const;
    const std::string& lastEvent(); //  notification of error
    // functions
    void addBook(book bk, int c);
    void addVisitor(visitor vt, int c);

    //business-logic funct
    int recieveBook(const visitor &vt, const book &bk, int c);
    int returnBook(visitor vt,book bk,int c);
    int updateDebtors(int c);
    const std::vector<std::string> &debtors() const;

    void sentUpdateToView(int c);

private:
    std::string lastEvent_;
    storageVisitor_t visitors_;
    storageBook_t books_;
    std::vector<std::string> debtors_;
};

#endif // MODEL_H
