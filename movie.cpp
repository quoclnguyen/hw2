#include "movie.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating):
    Product(category, name, price, qty)
    {
      genre_=genre;
      rating_=rating;

    }
Movie::~Movie()
{
}
std::set<std::string> Movie::keywords() const {
  std::set<std::string> a = parseStringToWords(name_);
  a.insert(convToLower(genre_));
  a.insert(convToLower(rating_));
  return a; 
}
std::string Movie::displayString() const{
  std::string priceCorrected = std::to_string(price_);
  priceCorrected = priceCorrected.substr(0, (priceCorrected.size() -4));
  std::string displayed = name_ + '\n' + "Genre: " + genre_ + " Rating: " + rating_ + '\n' + priceCorrected + ' ' + std::to_string(qty_) + " left.";
  return displayed; 

}
void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << std::endl;
}