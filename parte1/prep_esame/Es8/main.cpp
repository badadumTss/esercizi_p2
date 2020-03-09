#include <iostream>
using namespace std;

class A {
protected:
  virtual void h() {cout<<" A::h ";}
public:
  virtual void g() const {cout <<" A::g ";}
  virtual void f() {cout <<" A::f "; g(); h();}
  void m() {cout <<" A::m "; g(); h();}
  virtual void k() {cout <<" A::k "; h(); m(); }
  virtual A* n() {cout <<" A::n "; return this;}
};

class B: public A {

protected:
  virtual void h() {cout <<" B::h";}

public:
  virtual void g() {cout <<" B::g ";}
  void m() {cout <<" B::m "; g(); h();}
  void k() {cout <<" B::k "; g(); h();}
  B* n() {cout <<" B::n "; return this;}
};

class C: public B {
protected:
  virtual void h() const {cout <<" C::h ";}
public:
  virtual void g() {cout <<" C::g ";}
  void m() {cout <<" C::m "; g(); k();}
  void k() const {cout <<" C::k "; h();}
};

int main(){
  A* p2 = new B(); A* p3 = new C(); B* p4 = new B(); B* p5 = new C(); const A* p6 = new C();

  p2->f();			// A::f A::g B::h
  cout << endl;
  p2->m();			// A:m A::g B::h
  cout << endl;
  p3->k();			// C::k C::h
  // B::k C::g B::h ATETNZIONE: Guadagnare o perdere const equivale a cambiare firma!!!!!!!!!!!!!!
  cout << endl;
  p3->f();			// A::f A::g B::h
  cout << endl;
  p4->m();			// B::m B::g B::h
  cout << endl;
  p4->k();			// B::k B::g B::h
  cout << endl;
  p5->g();			// C::g 
  cout << endl;
  // p6->k();			// calling k casts away constness, dato che staticamente è un A* e la firma base di k non è const
  cout << endl;
  p6->g();			// A::g 
  cout << endl;
  (p3->n())->m();		// B::n B::m B::g B::h
  // POTREBBE PERÒ ANCHE FARE AL POSTO DI B::m, A::m A::g B::h!! dipende da cosa prevale: saticità o dinamicità del puntatore?? propendo per dinamicità // E INVECE HA VINTO STATICITà!! a compile-time il compilatore ha bindato un ritorno di tipo A* e quindi la chiamata ->m() è su un oggetto A*!!!!!!!!
  // cout << endl;
  (p3->n())->g();		// B::n A::g // stesso discorso di prima
  cout << endl;
  (p3->n())->n()->g();		// B::n B::n A::g // STESSO DISCORSO, mettere prima un ->n() non modifica quello che il compilatore può vedere
  cout << endl;
  (p5->n())->g();		// B::n C::g
  cout << endl;
  (p5->n())->m();		// B::n B::m C::g B::h Attento!! qui h acquista const -> un'altra firma!!!!
  cout << endl;
  (dynamic_cast<B*>(p2))->m();	// B::m B::g B::h
  cout << endl;
  (static_cast<C*>(p3))->k();	// C::k C::h
  cout << endl;
  (static_cast<B*>(p3->n()))->g(); // B::n C::g
  return 0;
}
