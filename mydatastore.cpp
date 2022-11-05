#include "mydatastore.h"

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){

}

void MyDataStore::addProduct(Product* p){
  products.insert(p);
  //make a set of strings associated with product.
  //std::set<std::string> temp = parseStringToWords(p->getName());
  std::set<std::string> temp = p->keywords();
  typename std::set<std::string>::iterator it = temp.begin();
  while (it != temp.end()){
    if (matchingTerms.find(*it) == matchingTerms.end()){//if keyword does not exist yet
      std::set<Product*> newSet;
      newSet.insert(p);
      matchingTerms.insert(std::pair<std::string,std::set<Product*> >(*it, newSet));
    }
    else{
      (matchingTerms[*it]).insert(p);
    }
    ++it;
  }
}

void MyDataStore::addUser(User* u){ 
  std::deque<Product*> cart;
  users.insert(std::pair<User*,std::deque<Product*> >(u, cart));
  usernames.insert(std::pair<std::string, User*> ((u->getName()),u));
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
  // 0 = AND, 1 = OR
  //make a set of the strings in map, set of input 
  // then put that through setIntersect/setUnion, pushes back into vector then returns
  std::set<Product*> s1;
  std::set<Product*> s2;
  std::vector<Product*> final;
  if (matchingTerms.find(terms[0])== matchingTerms.end() && terms.size()==1) {
    return final;
  }
  
  if (matchingTerms.find(terms[0])!=matchingTerms.end()){ // if word actually exists in map
    s1 = matchingTerms[terms[0]];
    if (terms.size() == 1){
      typename std::set<Product*>::iterator it = s1.begin();
      while (it != s1.end()){
        final.push_back(*it);
        ++it;
      }
      return final;
    }
  }
  if (matchingTerms.find(terms[1])!=matchingTerms.end()){
    s2 = matchingTerms[terms[1]];
  }
  if (type ==0){
    s1 = setIntersection(s1,s2);
  }
  else if (type ==1){
    s1 = setUnion(s1,s2);
  }
  for(unsigned int i = 2; i< terms.size(); i++){
    if(matchingTerms.find(terms[i])!=matchingTerms.end()){
      s2 = matchingTerms[terms[i]];
    }
    else{s2.clear();}
    if (type ==0){
      s1 = setIntersection(s1,s2);
    }
    else if (type ==1){
      s1 = setUnion(s1,s2);
    }
  }
  typename std::set<Product*>::iterator it = s1.begin();
  while (it != s1.end()){
    final.push_back(*it);
    ++it;
  }
  return final;
}
void MyDataStore::dump(std::ostream& ofile){
  ofile << "<products>\n";
  typename std::set<Product*>::iterator it = products.begin();
  while (it != products.end()){
    Product* temp1 = *it;
    (*it)->dump(ofile);
    ++it;
    delete temp1;
  }
  ofile<< "</products>\n";
  ofile << "<users>\n";
  typename std::map<User*, std::deque<Product*>>::iterator it2 = users.begin();
  while (it2 != users.end()){
    User* temp2 = (*it2).first;
    ((*it2).first)->dump(ofile);
    ++it2;
    //typename std::deque<Product*>:: iterator it3 = ((*it2).second).begin();
    //while (it3!= ((*it2).second).end()){ /*/delete *it3;/*/ }
    delete temp2;

  }
  ofile << "</users>\n";
  //users.clear();
  //usernames.clear();
  //products.clear();
  //matchingTerms.clear();
}
void MyDataStore::addToCart (std::string user, Product* p){

  if((usernames.find(user) != usernames.end()) && (products.find(p) != products.end())){
    users[usernames[user]].push_back(p);
  }
  else{
    std::cout << "Invalid request" << std::endl;
  }

}
void MyDataStore::viewCart(std::string user){
  if(usernames.find(user)!=usernames.end()){ // if users exist.
    User* u = usernames[user];
    typename std::deque<Product*>::iterator it = users[u].begin();
    std::string currentItem = "";
    int index = 1;
    while(it != users[u].end()){ // iterate thru 
      currentItem = (*it)->displayString();
      std::cout<<"Item " <<index << std::endl <<currentItem <<std::endl;
      ++index;
      ++it;
    }
    //delete u;
  }
  else{
    std::cout <<"Invalid username" << std::endl;
  }

}
void MyDataStore::buyCart(std::string user){
  std:: deque<Product*> remaining;
  if(usernames.find(user)!= usernames.end()){
    User* u = usernames[user];
    while(users[u].size() >0){
      //checks if item is in stock + user has enough money
      if ((users[u].front())->getQty() >0 && (u->getBalance() >= (users[u].front())->getPrice())){
        u->deductAmount((users[u].front())->getPrice()); //subtract from user balance
        (users[u].front())->subtractQty(1); //subtract from item qty
      }
      else{ //push items you can't buy to a new deque;
        remaining.push_back(users[u].front());
      }
      //delete users[u].front();
      users[u].pop_front(); 
    }
    //users[u] = remaining;
  }
  else{ 
    std::cout << "Invalid username" << std::endl;
    return;
    }
  users[usernames[user]] = remaining; // update cart with remaining items
}