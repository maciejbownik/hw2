#include "movie.h"
#include <sstream>

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty,
  const std::string genre, const std::string rating) :
  Product(category, name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {};

std::set<std::string> Movie::keywords()const{
  std::set<std::string> keychain = parseStringToWords(name_);

  keychain.insert(convToLower(genre_));
  //keychain.insert(rating_);

  return keychain;
}

std::string Movie::displayString()const{
  ostringstream display;

  display << name_ << "\n" <<
  "Genre: " << genre_ << " Rating: " << rating_ + "\n" <<
  price_ << " " << qty_ << " left.\n";

  return display.str();
}

void Movie::dump(std::ostream& os) const {
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << 
    "\n" << genre_ << "\n" << rating_ << endl;
}
