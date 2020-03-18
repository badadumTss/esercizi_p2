#include "list.h"
#include <iostream>

int main(){
  list<int> a;
  for(int i=0; i<10; ++i)
    a.push_back(i);
  std::cout << "inserimento funziona!!" << std::endl;
  for(list<int>::const_iterator it = a.begin(); it != a.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;
}
