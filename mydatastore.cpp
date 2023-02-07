#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include "mydatastore.h"
#include "util.h"
#include "user.h"
#include "product.h"

using namespace std;

// destructor 
MyDataStore::~MyDataStore()
{
	// deletes all dynamically-allocated Product objects
	// which are held in data member 
	for (size_t i = 0; i < products_.size(); i++) {
		delete products_[i];
	}

	// deletes all dynamically-allocated User objects
	// which are held in data member 
	for (size_t j = 0; j < users_.size(); j++) {
		delete users_[j];
	}
}

void MyDataStore::addProduct(Product* p)
{
	// adds product to store's list of products 
	products_.push_back(p);
	// finds every possible keyword contained in all of 
	// new product's info and stores it in a new set 
	set<string> allKeys = p->keywords();
	// sets each element in new set to be a key in 
	// data member that stores all keywords and corresponding 
	// products that contain it 
	for (set<string>::iterator i = allKeys.begin(); i != allKeys.end(); ++i) {
		keyWords_[*i].push_back(p);
	}
}

void MyDataStore::addUser(User* u)
{
	// adds user to store's list of users 
	users_.push_back(u);
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
	// clears data member that holds most recent 
	// search results 
	currHits_.clear();
	// runs when user did not provide terms to search for 
	if (terms.size() == 0) {
		cout << "No key terms have been entered.";
	}

	// new list to hold search results and return 
	// at function's end 
	vector<Product*> results;
	
	// new set to hold search results (to be converted 
	// vector)
	set<Product*> productsFound;
	// intersection (AND search aka all terms)
	if (type == 0) {
		// iterates through all search terms provided and 
		// if found in keyword data member, insert all 
		// of keyword's vector value into new set that 
		// holds current products 
		for (size_t i = 0; i < terms.size(); i++) {
			if (keyWords_.find(terms[i]) != keyWords_.end()) {
				set<Product*> currProducts;
				for (size_t j = 0; j < keyWords_[terms[i]].size(); j++) {
					currProducts.insert(keyWords_[terms[i]][j]);
				}
				// implements AND functionality by only including
				// products that contain ALL provided keywords 
				productsFound = setIntersection(productsFound, currProducts);
			}
		}
	}
	// union (OR search aka at least one term) 
	else if (type == 1) {
		// iterates through all search terms provided and 
		// if found in keyword data member, insert all 
		// of keyword's vector value into new set that 
		// holds current products 
		for (size_t i = 0; i < terms.size(); i++) {
			if (keyWords_.find(terms[i]) != keyWords_.end()) {
				set<Product*> currProducts;
				for (size_t j = 0; j < keyWords_[terms[i]].size(); j++) {
					currProducts.insert(keyWords_[terms[i]][j]);
				}
				// implements OR functionality by including 
				// all products that contain at least one of the 
				// provided keywords 
				productsFound = setUnion(productsFound, currProducts);
			}
		}
	}

	// converts set to vector 
	for (set<Product*>::iterator it = productsFound.begin(); it != productsFound.end(); ++it) {
		results.push_back(*it);
	}
	// updates data member that holds latest 
	// search results 
	currHits_ = results;
	// return list of all hits 
	return results;
}

User* MyDataStore::findUserPointer(std::string username)
{
	// iterates through all of users in data member 
	// user list until username's match and returns 
	// pointer 
	for (size_t i = 0; i < users_.size(); i++) {
		if (users_[i]->getName() == username) {
			return users_[i];
		}
	}
	// runs if user does not exist in database 
	return NULL;
}

void MyDataStore::viewCart(User* u)
{
    // checks if user object passed in exists 
		if (cart_.find(u) != cart_.end()) {
        // buffer to do nothing 
				int temp;
    }
    else {
        cout << "Invalid username";
        return;
    }

		// iterates through user's cart, lists and 
		// displays each item's data in required 
		// format 
    for (size_t i = 0; i < cart_[u].size(); i++) {
        cout << "Item " << i+1 << endl;
				cout << cart_[u][i]->displayString() << endl;
				cout << endl;
    }
}

void MyDataStore::addCart(User* u, size_t hitIndex)
{
	// if no user is provided
	if (u == NULL) {
		cout << "Invalid request";
		return;
	}
	// if hit index is less than 0 or greater than 
	// results list size 
	if ((hitIndex < 0) || (hitIndex > currHits_.size())) {
		cout << "Invalid request";
		return;
	}
	// adds product to user's cart 
	cart_[u].push_back(currHits_[hitIndex - 1]);
	return;
}

void MyDataStore::buyCart(User* u)
{
		//checks if user object passed in exists 
    if (cart_.find(u) != cart_.end()) {
        // buffer to do nothing 
				int temp;
    }
    else {
        cout << "Invalid username";
        return;
    }

		// iterates through user's cart 
    for (size_t i = 0; i < cart_[u].size(); i++) {
        // runs if product is in stock and 
				// user has enough money to buy it 
				if ((cart_[u][i]->getQty() > 0) && (u->getBalance() >= cart_[u][i]->getPrice())) {
						// subtracts quantity from product's info 
						cart_[u][i]->subtractQty(1);
						// subtracts price from user's balance 
						u->deductAmount(cart_[u][i]->getPrice());
						// erases product from user's cart 
						cart_[u].erase(cart_[u].begin() + i);
						// accounts for erased element and shifted
						// position in vector 
						i--;
        }
    }
}

void MyDataStore::dump(ostream& ofile)
{
	// uses ostream to output store's database to 
	// text file after all transactions have occurred 
	// in required format 
	ofile << "<products>" << endl;
	for (size_t i = 0; i < products_.size(); i++) {
		products_[i]->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	for (size_t i = 0; i < users_.size(); i++) {
		users_[i]->dump(ofile);
	}
	ofile << "</users>" << endl;
}

