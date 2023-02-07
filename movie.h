#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "util.h"
#include <iostream>
#include <string>

// product-derived object 
class Movie : public Product {
public:
	// constructor
	Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
	// destructor
	~Movie();
	// returns a strings keywords
	std::set<std::string> keywords() const;
	// displays book information in given format to console
	std::string displayString() const;
	// displays book information in given format to file
	void dump(std::ostream& os) const;


private:
	std::string genre_;
	
	std::string rating_;
};
#endif