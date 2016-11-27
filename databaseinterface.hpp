#ifndef DATABASEINTERFACE_HPP
#define DATABASEINTERFACE_HPP

#include "visitor.h"
#include "book.h"
#include <vector>
#include <utility>
class dataBaseInterface
{
public:
    virtual std::vector<visitor>& visitors() = 0;
    virtual std::vector<book>& books() = 0;
	virtual void save(std::vector<visitor> &vts, std::vector<book> &bks) = 0;
};

class dataBaseInterface1: public dataBaseInterface
{
public:
    dataBaseInterface1(std::vector<visitor> &_vis,std::vector<book> &_bo):visitors_(_vis), books_(_bo){
    }
    ~dataBaseInterface1(){
    }
    virtual std::vector<visitor>& visitors(){
        return visitors_;
    }
    virtual std::vector<book>& books(){
        return books_;
    }
	virtual void save(std::vector<visitor> &vts, std::vector<book> &bks) {
		books_ = bks;
		visitors_ = vts;
	};
private:
    std::vector<book> books_;
    std::vector<visitor> visitors_;
};


class dataBaseInterface2 : public dataBaseInterface
{
public:
	dataBaseInterface2(std::vector<std::string> &_vis, std::vector<std::string> &_bo) {
		for (auto i : _vis) {
			visitors_.push_back(visitor(i));
		}
		for (auto i : _bo) {
			books_.push_back(book(i));
		}
	}
	~dataBaseInterface2() {
	}
	virtual std::vector<visitor>& visitors() {
		return visitors_;
	}
	virtual std::vector<book>& books() {
		return books_;
	}	
	virtual void save(std::vector<visitor> &vts, std::vector<book> &bks) {
		books_ = bks;
		visitors_ = vts;
	};
private:
	std::vector<book> books_;
	std::vector<visitor> visitors_;
};


class dataBaseInterface3 : public dataBaseInterface
{
public:
	dataBaseInterface3(std::vector<std::string> &_vis, std::vector<std::pair <std::string, std::time_t> > &_bo) {
		for (auto i : _vis) {
			visitors_.push_back(visitor(i));
		}
		for (auto i : _bo) {
			books_.push_back(book(i.first));
		}
	}
	~dataBaseInterface3() {
	}
	virtual std::vector<visitor>& visitors() {
		return visitors_;
	}
	virtual std::vector<book>& books() {
		return books_;
	}
	virtual void save(std::vector<visitor> &vts, std::vector<book> &bks) {
	};
	std::vector<book> books_;
	std::vector<visitor> visitors_;
};



#endif // DATABASEINTERFACE_HPP
