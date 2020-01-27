#include <iostream>
using namespace std;

class A{
protected:
  virtual void j() { cout << " A::j "; }
public:
  virtual void g() const { cout << " A::g "; }
  virtual void f() { cout << " A::f "; g(); j(); }
  void m(){ cout << " A::m "; g(); j(); }
  virtual void k() {cout << " A::k "; j(); m(); }
  virtual A* n() { cout << " A::n "; return this; }  
};

class B: public A {
public:
  virtual void g() const override { cout <<" B::g "; }
  virtual void m() { cout <<" B::m "; g(); j(); }
  void k() { cout <<" B::k "; A::n(); }
  A* n() override { cout <<" B::n "; return this; }
};


class C: public A {                                         
private:                                                    
  void j() { cout <<" C::j "; }                               
public:                                                     
  virtual void g() { cout <<" C::g "; }                       
  void m() { cout <<" C::m "; g(); j(); }         
  void k() const { cout <<" C::k "; k(); }        
};

class D: public B {
protected:
  void j() { cout <<" D::j "; }
public:
  B* n() final { cout <<" D::n "; return this; }
  void m() { cout <<" D::m "; g(); j(); }
};

int main(){
  A* p1 = new D(); A* p2 = new B(); A* p3 = new C(); B* p4 = new D(); const A* p5 = new C();
  p1->g(); cout << endl;	// B::g
  p1->k(); cout << endl;	// B::k A::n
  p2->f(); cout << endl;	// A::f B::g A::j 
  p2->m(); cout << endl;	// A::m B::g A::j
  // p3->k(); cout << endl;	// A::k C::j A::m A::m A::g A::j  // OPPURE VA IN STACK OVERFLOW, Se all'inizio chiama C::k va in loop, il this li dentro è di tipo C* // ALLA FINE STACK OVERFLOW: UN METODO PUÒ GUADAGNARE L'ATTRIBUTO CONST
  p3->f(); cout << endl;	// A::f A::g C::j // ultimo è C::j, non A::j
  p4->m(); cout << endl;	// D::m B::g D::j
  p4->k(); cout << endl;	// B::k A::n
  p5->g(); cout << endl;	// A::g
  (p3->n())->m(); cout << endl;	// A::n A::m A::g C::j // C::j, non A::j -> può vedere un metodo anche se qusto ha avuto un upgrqade di privacy 
  (p3->n())->n()->g(); cout << endl; // A::n A::n A::g
  (p4->n())->m(); cout << endl;	     // D::n A::m B::g D::j // A::m non B::m, probabilmente ha a che fare col final
  // (p5->n())->g(); cout << endl;	     // BUH? final che vuol dire? comunque non const, dovrebbe dare errore compile time
  (dynamic_cast<B*>(p1))->m(); cout << endl; // D::m B::g D::j
  // (static_cast<C*>(p2))->k(); cout << endl;  // si che va in stack overflow, c::k() chiama se stessa all'infinito
  (static_cast<B*>(p3->n()))->g(); cout << endl; // A::n A::g // A::g invece che B::g, come funziona lo ststic_cast su puntatori polimorfi? vedere bene, anche la linea di prima non avevi capito bene

  return 0;
}
