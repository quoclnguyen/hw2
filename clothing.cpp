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
  std::set<std::string> brandName = parseStringToWords(brand_);
  a.insert(brandName.begin(), brandName.end());
  a.insert(size_);
  return a; 
}
std::string Clothing::displayString() const{
  std::string priceCorrected = std::to_string(price_);
  priceCorrected = priceCorrected.substr(0, (priceCorrected.size() -4));
  std::string displayed = name_ + '\n' + "Size: " + size_ + " Brand: " + brand_ + '\n' + priceCorrected + ' ' + std::to_string(qty_) + " left.";
  return displayed; 
}
void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << std::endl;
}