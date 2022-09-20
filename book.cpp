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
  return a; 
}
std::string Book::displayString() const{
  return ""; //for now

}
void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << std::endl;
}