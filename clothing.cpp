#include "clothing.h"
#include <sstream>

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) :
Product(category, name, price, qty), size_(size), brand_(brand) {}

Clothing::~Clothing() {};

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> keychain = parseStringToWords(name_);

  set<string> brandSet = parseStringToWords(brand_);
  set<string>::iterator it;

  for(it=brandSet.begin(); it != brandSet.end(); it++){
    keychain.insert(*it);
  }
  keychain.insert(convToLower(size_));

	return keychain;
}

std::string Clothing::displayString() const {
  ostringstream display;

  display << name_ << "\n" <<
  "Size: " << size_ << " Brand: " << brand_ << "\n" <<
  price_ << " " << qty_ << " left.\n";

	return display.str();
}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << 
    "\n" << size_ << "\n" << brand_ << std::endl;
}




