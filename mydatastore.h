#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include<map>


class MyDataStore : public DataStore {

  public:
  MyDataStore();
	~MyDataStore();

  void addProduct(Product* toAdd) override;

  void addUser(User* newUser) override;

  std::vector<Product*> search(std::vector<std::string>& terms, int type) override;

  void dump(std::ostream& ofile) override;


  void addToCart(std::string user, int hitResultIndex);
  void viewCart(std::string user);
  void buyCart(std::string user);

	void printProducts();



  private:
  std::vector<Product*> products_;
  std::map<std::string, User*> users_;
  std::map<std::string, std::set<Product*>> keywordMap_;
  std::map<std::string, std::vector<Product*>> userCarts_;
  std::vector<Product*> lastSearchResults_;
};

#endif