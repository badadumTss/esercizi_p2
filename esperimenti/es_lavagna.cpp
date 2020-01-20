#include <iostream>
using namespace std;

class A{
  void h() {cout << "A::h ";}
public:
  virtual void g() {cout << "A::g ";}
  virtual void f() {cout << "A::f "; g(); h();}
  void m() {cout << "A::m "; g(); h();}
  virtual void k() {cout << "A::k "; g(); h(); m();}
  A* n() {cout << "A::n "; return this;}
};

class B:public A{
  void h() {cout << "A::h ";}
public:
  void g() {cout << "B::g ";}
  void f() {cout << "B::f "; g(); h();}
  void m() {cout << "B::m "; g(); h();}
  void k() {cout << "B::k "; g(); h(); m();}
  A* n() {cout << "B::n "; return this;}
};

int main(){
  B* b = new B();
  A* a = new B();
  b->f(); cout << endl;
  b->m(); cout << endl;
  b->k(); cout << endl;
  a->f(); cout << endl;
  a->m(); cout << endl;
  a->k(); cout << endl;
  (b->n())->g(); cout << endl;
  (b->n())->n()->g(); cout << endl; // B::n A::n B::g !! g è virtuale e quindi il tipo dinamico della seconda n() anche se il tipo statico è A NON CAMBIA
  (a->n())->g(); cout << endl;
  (a->n())->m(); cout << endl;
  return 0;
}
