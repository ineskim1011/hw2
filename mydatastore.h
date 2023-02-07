#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include "product.h"
#include "util.h"
#include "user.h"
#include "datastore.h" 

// DataStore-derived object 
class MyDataStore : public DataStore {
public:
	// destructor 
	~MyDataStore();
	// adds product pointer to data member (Product* vector)
	// that holds all products that store carries 
	void addProduct(Product* p);
	// adds user pointer to data member (User* vector)
	// that holds all users held in store database 
	void addUser(User* u);
	// search function that allows user to implement an AND
	// or OR search by specifying through type #
	// and providing list of keywords 
	std::vector<Product*> search(std::vector<std::string>& terms, int type);
	// allows user to add a product from search result list
	// to their cart
	void addCart(User* u, size_t hitIndex);
	// allows specific user to view all items in their cart
	void viewCart(User* u);
	// allows specific user to purchase all items in their cart
	void buyCart(User* u);
	// outputs store's database to text file after all 
	// transactions have occurred 
	void dump(std::ostream& ofile);
	// takes in a string (username) and if found, returns
	// pointer to User object that bares that username 
	User* findUserPointer(std::string username);

private:
	// holds all of products that store sells
	std::vector<Product*> products_;
	// holds all users in store's database
	std::vector<User*> users_;
	// key: holds all possible keywords of every object 
	// value: holds list of all products that include 
	// that keyword 
	std::map<std::string, std::vector<Product*>> keyWords_;
	// key: a specific user
	// value: holds list of all products in that user's cart
	std::map<User*, std::vector<Product*>> cart_;
	// holds list of search results from most recent search 
	std::vector<Product*> currHits_;
};
#endif