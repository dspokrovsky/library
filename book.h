#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <ctime>

class book{

public:
    //book(std::string _n): name_(_n)

    const std::string& name() const{
        return name_;
    }
    std::string& name(){
        return name_;
    }

private:
    std::string name_;
    struct tm time_;

};

#endif // BOOK_H
