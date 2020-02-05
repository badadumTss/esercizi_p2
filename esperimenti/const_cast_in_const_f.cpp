#include <iostream>

class A{
  const int* ptr;
public:
  A(const int& i):ptr(new int(i)){}
  ~A(){ delete ptr; }
  int* f() const {
    return const_cast<int*>(ptr);
  }
  // compila e funziona: lo fa fare!! di fatto annulla il const su ptr
  int getN() const { return *ptr; }
};

int main(){
  A a(10);
  *(a.f()) = 2;
  std::cout << a.getN() << std::endl;
}
