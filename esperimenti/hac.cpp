#include <iostream>
using namespace std;

class A{
public:
  int a;
  virtual void f() const { cout << "A::f ";}
};

class B: public A{
public:
  int a;
  void f() const { cout << "B::f "; }
};

void F(const A& a){
  a.f();
}

int main(){
  A o1; B o2;
  F(o1);
  F(o2);
  return 0;
}

/*COMPILA E FUNZIONA:
  passaggio di oggetto tramite riferimento costante non elimina specializzazione dell'oggetto!! 
*/
