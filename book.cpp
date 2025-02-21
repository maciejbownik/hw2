#include "book.h"
#include <sstream>

using namespace std;


Book::Book(const std::string& category, const std::string& name, double& price, int& qty, const std::string& ISBN, const std::string& Author)
: Product(category, name, price, qty), isbn_(ISBN), author_(Author) {}

Book::~Book() {};

std::set<std::string> Book::keywords() const{

  std::set<std::string> keychain = parseStringToWords(name_);
  
  //set<string>::iterator it;

  set<string> authorSet = parseStringToWords(author_);
  for(set<string>::iterator it = authorSet.begin(); it != authorSet.end(); it++){
    keychain.insert(*it);
  } 
	keychain.insert(convToLower(isbn_));
  
  return keychain;
}

std::string Book::displayString() const{

  ostringstream display;

  display << name_ << "\n" 
  << "Author: " << author_ << " ISBN: " << isbn_ << "\n"
  << price_ << " " << qty_ << " left.\n";

  return display.str();
}

void Book::dump(std::ostream& os) const 
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << 
    "\n" << isbn_ << "\n" << author_ << std::endl;
}



