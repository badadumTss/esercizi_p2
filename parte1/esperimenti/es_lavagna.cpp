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
  void h() {cout << "B::h ";}
public:
  virtual void g() {cout << "B::g ";}
  void m() {cout << "B::m "; g(); h();}
  void k() {cout << "B::k "; g(); h(); m();}
  B* n() {cout << "B::n "; return this;}
};

int main(){
  B* b = new B(); A* a = new B();
  b->f(); cout << endl;		    // A::f B::g A::h
  b->m(); cout << endl;		    // B::m B::g B::h
  b->k(); cout << endl;		    // B::k B::g B::h B::m B::g B::h
  a->f(); cout << endl;		    // A::f B::g A::h
  a->m(); cout << endl;		    // A::m B::g A::h
  a->k(); cout << endl;		    // B::k B::g B::h B::m B::g B::h
  (b->n())->g(); cout << endl;	    // B::n B::g
  (b->n())->n()->g(); cout << endl; // B::n B::n B::g 
  (a->n())->g(); cout << endl;	    // B::n B::g
  (a->n())->m(); cout << endl;	    // B::n A::m B::g A::h
  return 0;
}

// tutto giusto al primo colpo!!!!!
