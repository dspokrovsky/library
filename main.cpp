#include <iostream>
#include "controler.h"
#include "view.h"
#include "model.h"
#include "controler.h"
#include "book.h"
#include "visitor.h"
#include <utility>
#include <ctime>
#include "databaseinterface.hpp"
#include <algorithm>

int main()
{
	// fill the model;
	//fisrt database
	std::vector <book> b = { book("Fahrenheit 451"),book("The Martian Chronicles"),book("Green Town") };
	std::vector <visitor> v = { visitor("Ilya Vesel"),visitor("Jon Snow"), visitor("Dave") };
	//second db
	std::vector <std::string> b2 = { "Fahrenheit 451","a","aa","bb","cc","dd","kk" };
	std::vector <std::string> v2 = { "qwer","a","aa","bb","cc" };
	//third db
	std::vector <std::pair <std::string, time_t> > b3 = { {"a",1 },{"aa",1 },{"bb",1 },{"cc",1 },{"dd",1 },{"kk",1 } };
	std::vector <std::string> v3 = { "qwer","a","aa","bb","cc" };


	std::cout << " CHOSE DATABASE: 1 2 3 " << std::endl;
	std::shared_ptr<dataBaseInterface> p;
	int c;
	std::cin >> c;
	if (c == 1) {
		dataBaseInterface1 D(v, b);
		std::shared_ptr<dataBaseInterface1> ptr = std::make_shared<dataBaseInterface1>(D);
		p = ptr;
	}
	if (c == 2) {
		dataBaseInterface2 D2(v2, b2);
		std::shared_ptr<dataBaseInterface2> ptr2 = std::make_shared<dataBaseInterface2>(D2);
		p = ptr2;
	}
	if (c == 3) {
		dataBaseInterface3 D3(v3, b3);
		std::shared_ptr<dataBaseInterface3> ptr3 = std::make_shared<dataBaseInterface3>(D3);
		p = ptr3;
	}
	else {
		std::cout << "wrong number...next time try 1 2 3";
		system("pause");
		return -1;
	}


    model mod(p);
    //let's give first book to the first user
    mod.recieveBook(mod.visitors()[0].name(),mod.books()[0].name() ,0);
    // set time = 100s(from 1970) of the book in UNIX for testing our time
    mod.books()[0].t() =100;
    view ui(&mod);
    controler contr(&mod);
    contr.start();
	p= nullptr;
	system("pause");
    return 0;
}
