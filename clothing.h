#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"
#include <iostream>
#include <string>
#include <set>

// product-derived object 
class Clothing : public Product {
public:
	// constructor
	Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
	// destructor
	~Clothing();
	// returns a strings keywords
	std::set<std::string> keywords() const;
	// displays book information in given format to console
	std::string displayString() const;
	// displays book information in given format to file
	void dump(std::ostream& os) const;


private:
	std::string size_;
	
	std::string brand_;
};
#endif