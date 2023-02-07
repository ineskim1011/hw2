#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */

// returns new set of elements that both s1 & s2 contain 
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
	// declares new set to return at function's end
	std::set<T> setInt;

	// if first set is empty, return second set only
	if (s1.size() == 0) {
		return s2;
	}

	// if second set is empty, return first set only 
	if (s2.size() == 0) {
		return s2;
	}

	// runs if both sets have at least one element; 
	// iterates through first set and if current 
	// element in first set is found in second set as well, 
	// insert it into new set 
	for (typename std::set<T>::iterator i = s1.begin(); i != s1.end(); ++i) {
		if (s2.find(*i) != s2.end()) {
				setInt.insert(*i);
		}
	}

// return new set 
return setInt;
}

// returns new set of elements that contains all 
// elements that exist between s1 & s2 
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
	// declares new set to return at function's end
	std::set<T> setUni;

	// if first set is empty, return second set only
	if (s1.size() == 0) {
		return s2;
	}

	// if second set it empty, return first set only 
	if (s2.size() == 0) {
		return s1;
	}

	// iterates through first set and inserts every 
	// element into new set
	for (typename std::set<T>::iterator i = s1.begin(); i != s1.end(); ++i) {
		setUni.insert(*i);
	}

	// iteratres through second set and if current element 
	// in second set is found in the new set (aka already added)
	// it skips it and does not add it again
	for (typename std::set<T>::iterator i = s2.begin(); i != s2.end(); ++i) {
		if (setUni.find(*i) != setUni.end()) {
			continue;
		}
		else {
			setUni.insert(*i);
		}
	}

	// return new set 
	return setUni;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
