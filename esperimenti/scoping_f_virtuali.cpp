#include <iostream>

class A{
public:
  virtual void k() const { std::cout << "A::k "; } 
};

class B: public A{
public:
  virtual void k() { std::cout << "B::k "; }
};

class C: public B{
public:
  void k() const { std::cout << "C::k const "; }
  void k() { std::cout << "C::k "; }
};


int main(){
  A* p1 = new C();
  B* p2 = new C();
  p1->k();
  std::cout << std::endl;
  p2->k();
  std::cout << std::endl;
  return 0;
}

/*
un metodo virtuale può quindi saltare n generazioni, più metodi virtuali "sovraccaricati" nella gerarchia non ambiguano se è possibile disambiguarli per la firma
 */
