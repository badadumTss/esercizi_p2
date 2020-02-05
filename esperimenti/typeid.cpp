#include <iostream>
#include <typeinfo>

class A{};

int main(){
  typeid(A) == typeid(const A&) ? std::cout << "1 si " << std::endl : std::cout << "1 no " << std::endl; // 1 si!! top
  typeid(A*) == typeid(A) ? std::cout << "2 si " << std::endl : std::cout << "2 no " << std::endl; // no, ma era prevedibile
  return 0;
}
