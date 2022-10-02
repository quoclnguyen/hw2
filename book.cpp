#include "book.h"

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author):
    Product(category, name, price, qty)
    {
      isbn_=isbn;
      author_=author;

    }
Book::~Book()
{
}
std::set<std::string> Book::keywords() const {
  std::set<std::string> a = parseStringToWords(name_);
  std::set<std::string> authorName = parseStringToWords(author_);
  a.insert(isbn_);
  a.insert(authorName.begin(), authorName.end());
  return a; 
}
std::string Book::displayString() const{
  std::string priceCorrected = std::to_string(price_);
  priceCorrected = priceCorrected.substr(0, (priceCorrected.size() -4));
  std::string displayed = name_ + '\n' + "Author: " + author_ + " ISBN: " + isbn_ + '\n' + priceCorrected + ' ' + std::to_string(qty_) + " left.";
  return displayed; 

}
void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << std::endl;
}