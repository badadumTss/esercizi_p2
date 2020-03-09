#include <iostream>
class A{
public:
  virtual void f() { std::cout << "A::f "; }
  virtual void m() { std::cout << "A::m "; }
};

class B: public A{
public:
  virtual void f() { std::cout << "B::f "; }
  void m() const { std::cout << "B:m "; }
};

void fun(A& o1, A& o2){
  o1.f();
  o2.f();
  // funziona!! anche i riferimenti sono polimorfi
  o1.m();
  o2.m();
  // funziona pure allo stesso modo dei puntatori sembrerebbe
}

int main(){
  A a; B b;
  fun(a,b);
  return 0;
}
