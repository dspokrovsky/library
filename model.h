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
    //using storage_t = std::map< visitor, std::vector<detail::visData_t> >;
    using storage_t = std::vector< visitor >;

    using storageBook_t = std::vector<book>;
    model(){}
    explicit model(storage_t vsts, storageBook_t bks);
    // accessors
    storage_t& visitors(int c);
    storage_t& visitors();
    const storage_t& visitors() const;
    std::vector<book>& books();
    std::vector<book>& books(int c);
    const std::vector<book>& books() const;
    // functions
    void addBook(book bk, int c);
    void addVisitor(visitor vt, int c);
    //recst of the task
    int recieveBook(visitor vt,book bk,int c);
    int returnBook(visitor vt,book bk,int c);
    int updateDebtors(int c);
    std::vector <visitor>& debtors();
    void donoth(int c);

private:
    storage_t visitors_;
    storageBook_t books_;
    std::vector<visitor> debtors_;
};

#endif // MODEL_H
