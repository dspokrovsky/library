#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <visitor.h>
#include <book.h>
#include <ctime>
#include <vector>
#include <observer.h>
#include <utility>


class model: public observable
{

public:
    using storageVisitor_t = std::vector< visitor >;
    using storageBook_t = std::vector<book>;
    model(){}
    explicit model(storageVisitor_t vsts, storageBook_t bks);
    ~model(){}
    // accessors
    storageVisitor_t& visitors(int c);
    storageVisitor_t& visitors();
    const storageVisitor_t& visitors() const;
    std::vector<book>& books();
    std::vector<book>& books(int c);
    const std::vector<book>& books() const;
    // functions
    void addBook(book bk, int c);
    void addVisitor(visitor vt, int c);

    //functions from the task
    int recieveBook(visitor vt,book bk,int c);
    int returnBook(visitor vt,book bk,int c);
    int updateDebtors(int c);
    const std::vector<std::string> &debtors() const;
    void donoth(int c);

private:
    storageVisitor_t visitors_;
    storageBook_t books_;
    std::vector<std::string> debtors_;
};

#endif // MODEL_H
