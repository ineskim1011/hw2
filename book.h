#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include <iostream>
#include <string>
#include <set>

// product-derived object 
class Book : public Product {
public:
	// constructor
	Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author);
	// destructor 
	~Book();
	// returns a strings keywords
	std::set<std::string> keywords() const;
	// displays book information in given format to console
	std::string displayString() const;
	// displays book information in given format to file
	void dump(std::ostream& os) const;


private:
	std::string ISBN_;
	
	std::string author_;
};
#endif