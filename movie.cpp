#include <sstream>
#include <iostream>
#include <iomanip>
#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std;

// constructor 
Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating):
	// initialization line 
	Product(category, name, price, qty)
{
	// initializes Movie specific data members
	genre_ = genre;
	rating_ = rating;
}

// destructor 
Movie::~Movie()
{

}

set<string> Movie::keywords() const 
{
	// creates new set to hold keywords from title
	// by calling parsing function I wrote in util.cpp
	set<string> titleWords = parseStringToWords(name_);
	// creates another set to hold keywords from 
	// genre using same method 
	set<string> genreWords = parseStringToWords(genre_);
	// creates final set to hold union of title and 
	// genre name keywords 
	set<string> movieWords = setUnion(titleWords, genreWords);
	// return final set holding all movie's keywords 
	return movieWords;
}

string Movie::displayString() const
{	
	// create string to return at function's end
	string movieDisplay = "";
	// append to string to display Movie's information 
	// in required format 
	movieDisplay.append(name_);
	movieDisplay.append("\nGenre: ");
	movieDisplay.append(genre_);
	movieDisplay.append(" Rating: ");
	movieDisplay.append(rating_);
	movieDisplay.append("\n");
	movieDisplay.append(to_string(price_));
	movieDisplay.append(" ");
	movieDisplay.append(to_string(qty_));
	movieDisplay.append(" left.");
	// return new string 
	return movieDisplay;
}

void Movie::dump(ostream& os) const
{
	// use ostream to output Movie information 
	// to text file in required format 
	os << "movie\n" << name_ << "\n" << price_ << "\n";
	os << qty_ << "\n" << genre_ << "\n" << rating_ << "\n";
}