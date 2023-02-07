#include <sstream>
#include <iostream>
#include <iomanip>
#include <set>
#include "clothing.h"
#include "product.h"
#include "util.h"

using namespace std;

// constructor 
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand):
	// initialization line 
	Product(category, name, price, qty)
{
	// initializes Clothing specific data members 
	size_ = size;
	brand_ = brand;
}

// destructor
Clothing::~Clothing()
{

}

set<string> Clothing::keywords() const 
{
	// creates new set to hold keywords from item name 
	// by calling parsing function I wrote in util.cpp
	set<string> nameWords = parseStringToWords(name_);
	// creates another set to hold keywords from 
	// brand's name using same method 
	set<string> brandWords = parseStringToWords(brand_);
	// creates final set to hold union of item name and 
	// brand name keywords 
	set<string> clothesWords = setUnion(nameWords, brandWords);
	// inserts size string into final set (no need to parse)
	clothesWords.insert(size_);
	// return final set holding all book's keywords 
	return clothesWords;
}

string Clothing::displayString() const
{
	// create string to return at function's end 
	string clothingDisplay = "";
	// append to string to display Movie's information 
	// in required format 
	clothingDisplay.append(name_);
	clothingDisplay.append("\nSize: ");
	clothingDisplay.append(size_);
	clothingDisplay.append(" Brand: ");
	clothingDisplay.append(brand_);
	clothingDisplay.append("\n");
	clothingDisplay.append(to_string(price_));
	clothingDisplay.append(" ");
	clothingDisplay.append(to_string(qty_));
	clothingDisplay.append(" left.");
	// return new string 
	return clothingDisplay;
}

void Clothing::dump(ostream& os) const
{
	// use ostream to output CLothing information 
	// to text file in required format 
	os << "clothing\n" << name_ << "\n" << price_ << "\n";
	os << qty_ << "\n" << size_ << "\n" << brand_ << "\n";
}