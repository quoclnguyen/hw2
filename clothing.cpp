#include "clothing.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand):
    Product(category, name, price, qty)
    {
      size_=size;
      brand_=brand;

    }
Clothing::~Clothing()
{
}
std::set<std::string> Clothing::keywords() const {
  std::set<std::string> a = parseStringToWords(name_);
  return a; 
}
std::string Clothing::displayString() const{
  return ""; //for now

}
void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << std::endl;
}