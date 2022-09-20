#include "product.h"
#include "util.h"

class Book : public Product{
  public:
  Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
  ~Book();
  std::set<std::string> keywords() const;
  std::string displayString() const;
  void dump(std::ostream& os) const;

  protected:
  std::string author_;
  std::string isbn_;

};
