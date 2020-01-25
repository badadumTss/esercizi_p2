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

  p2->f();			// A::f B::g A::h // A::f A::g B::h PERCHÈ g cambia!! dentro ad a chiama g() che è la propria g
  cout << endl;
  p2->m();			// B::m B::g B::h // A::m (m NON È virtuale!!!!) A::g come sopra
  cout << endl;
  p3->k();			// C::k C::h
  cout << endl;
  p3->f();			// A::f C::g C::h <- controllare ultimo
  cout << endl;
  p4->m();			// B::m B::g B::h
  cout << endl;
  p4->k();			// B::k B::g B::h
  cout << endl;
  p5->g();			// C::g
  cout << endl;
  // p6->k();			// C::k C::h // NON COMPILA ALLA FINE: dato che la firma in C cambia per la name hiding rule il compilatore vede solamente void A::k() {...} NON COSTANTE 
  cout << endl;
  p6->g();			// A::g oppure NON COMPILA: calling g casts away constness per la name-hiding rule // ALLA FINE COMPILA
  cout << endl;
  (p3->n())->m();		// B::n C::m C::g C::k C::h
  cout << endl;
  (p3->n())->g();		// B::n C::g
  cout << endl;
  (p3->n())->n()->g();		// B::n B::n C::g
  cout << endl;
  (p5->n())->g();		// B::n C::g
  cout << endl;
  (p3->n())->m();		// B::n C::m C::g C::k C::h
  cout << endl;
  (dynamic_cast<B*>(p2))->m();	// B::m B::g B::h
  cout << endl;
  (static_cast<C*>(p3))->k();	// C::k C::h
  cout << endl;
  (static_cast<B*>(p3->n()))->g(); // C::g dovrebbe farglielo fare
  return 0;

  /*
    TOP hai cannato tutto: SEMPRE verificare: chi è il chiamante? la funzione esiste davvero o la name-hiding rule ha sfanculato tutto per un const?? Attento a Ranzato.
   */
}
