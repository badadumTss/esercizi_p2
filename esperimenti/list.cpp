#include <iostream>
#include <list>

class A{
  int* ptr;
public:
  A(const int& i = 0):ptr(new int(i)){}
  ~A(){ delete ptr; }
  A(const A& a):ptr(new int(*a)){}
  int& operator*() const { return *ptr; }
  int* operator->() const { return ptr; }
};

int main(){
  std::list<A> elem;
  for(int i=0; i<26; ++i)
    elem.push_back(A(i));
  for(const auto& it : elem){
    std::cout << *it << ' ';
  }
  std::cout << std::endl;
}
