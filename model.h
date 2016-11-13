#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <visitor.h>
#include <book.h>
#include <ctime>
#include <vector>

namespace  detail {
    struct visData_t{
        std::vector <book*> booksPtr_;
        struct tm visTime_;
    };
}


class model
{

public:
    model();
    explicit model(std::string data);
    // accessors
    std::map<visitor, detail::visData_t >& visitors(){
        return visitors_;
    }
    const std::map<visitor, detail::visData_t >& visitors() const{
        return visitors_;
    }
    std::vector<book>& books(){
        return books_;
    }
    const     std::vector<book>& books() const{
        return books_;
    }

    //const std::map<visitor, detail::visData_t> visitorsAdd();

private:
    std::map<visitor, detail::visData_t > visitors_;
    std::vector<book> books_;
};

#endif // MODEL_H
