#include "datastore.h"
#include "util.h"
#include <deque>
#include <map>

class MyDataStore: public DataStore{
  public:
  MyDataStore();
  ~MyDataStore();
  void addProduct(Product* p);
  void addUser(User* u);
  std::vector<Product*> search(std::vector<std::string>& terms, int type);
  void dump(std::ostream& ofile);
  void addToCart (std::string user, Product* p);
  void viewCart(std::string user);
  void buyCart(std::string user);
  
  private:

  //usernames maps the user's name to a user pointer
  //users map users to their carts
  std::map<std::string, User*> usernames; 
  std::map <User*, std::deque<Product*> > users; //users + their cart
  std::set <Product*> products;
  std::map <std::string, std::set<Product*> > matchingTerms;
};