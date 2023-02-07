#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    // declares new set of type string to return 
		// at function's end 
		std::set<std::string> keywords;
		
		// declares stringstream to read in string parameter 
		stringstream ss; 
    
		// inserts string parameter into stringstream
		ss << rawWords;
    
		// string variable to hold singular word 
		// read from string parameter 
		string singleWord;

		// runs so that each word in string parameter is 
		// accounted for 
    while (ss >> singleWord) {
        // uses ASCII to convert uppercase letters to 
				// lowercase
				for (size_t i = 0; i < singleWord.size(); i++) {
					if ((singleWord[i] >= 65) && (singleWord[i] < 91)) {
						singleWord[i] = singleWord[i] + 32;
					}
				}
				// if apostrophe is in the word, splits word into 
				// 2 substrings (before and after apostrophe location)
				// & adds it to keyword set if substring has 2 or more
				// letter 
				if (singleWord.find("'") != string::npos) {
					string substr1 = singleWord.substr(0, singleWord.find("'"));
					string substr2 = singleWord.substr(singleWord.find("'") + 1); 
					if (substr1.size() >= 2) {
						keywords.insert(substr1);
					}
					if (substr2.size() >= 2) {
						keywords.insert(substr2);
					}
				}
				// if period is in the word, splits word into 
				// 2 substrings (before and after period location)
				// & adds it to keyword set if substring has 2 or more 
				// letter
				else if (singleWord.find(".") != string::npos) {
					string substr1 = singleWord.substr(0, singleWord.find("."));
					string substr2 = singleWord.substr(singleWord.find(".") + 1); 
					if (substr1.size() >= 2) {
						keywords.insert(substr1);
					}
					if (substr2.size() >= 2) {
						keywords.insert(substr2);
					}
				}
				// if word has no punctuation, adds it to keyword set 
				// if string has 2 or more letter 
				else {
					if (singleWord.size() >= 2) {
						keywords.insert(singleWord);
					}
				}
		}
		return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
