#include <sstream>
#include <iostream>
#include <iomanip>
#include <set>
#include "book.h"
#include "product.h"
#include "util.h"

using namespace std;

// constructor 
Book::Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author):
	// initialization line 
	Product(category, name, price, qty)
{
	// initializes Book specific data members 
	ISBN_ = ISBN;
	author_ = author;
}

// destructor 
Book::~Book() {
	
}

set<string> Book::keywords() const 
{
	// creates new set to hold keywords from title 
	// by calling parsing function I wrote in util.cpp
	set<string> nameWords = parseStringToWords(name_);
	// creates another set to hold keywords from 
	// author's name using same method 
	set<string> authorWords = parseStringToWords(author_);
	// creates final set to hold union of title and 
	// author name keywords 
	set<string> bookWords = setUnion(nameWords, authorWords);
	// inserts ISBN number into final set (no need to parse)
	bookWords.insert(ISBN_);
	// return final set holding all book's keywords 
	return bookWords;
}

string Book::displayString() const
{
	// create string to return at function's end 
	string bookDisplay = "";
	// append to string to display Book's information 
	// in required format 
	bookDisplay.append(name_);
	bookDisplay.append("\nAuthor: ");
	bookDisplay.append(author_);
	bookDisplay.append(" ISBN: ");
	bookDisplay.append(ISBN_);
	bookDisplay.append("\n");
	bookDisplay.append(to_string(price_));
	bookDisplay.append(" ");
	bookDisplay.append(to_string(qty_));
	bookDisplay.append(" left.");
	// return new string 
	return bookDisplay;
}

void Book::dump(ostream& os) const
{
	// use ostream to output Book information 
	// to text file in required format 
	os << "book\n" << name_ << "\n" << price_ << "\n";
	os << qty_ << "\n" << ISBN_ << "\n" << author_ << "\n";
}