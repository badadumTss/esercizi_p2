#include <iostream>
using namespace std;
class B {
public:
  B() {cout<<"B() ";}
  virtual ~B() {cout<<"~B() ";}
  virtual void f() {cout << "B::f "; g(); j();}
  virtual void g() const {cout <<"B::g ";}
  virtual const B* j() {cout<<"B::j " ; return this;}
  virtual void k() {cout<<"B::k "; j(); m(); }
  void m() {cout <<"B::m "; g(); j();}
  virtual B& n() { cout<<"B::n "; return *this;}
};

class C: virtual public B {
public:
  C() {cout<<"C() ";}
  ~C() {cout<<"~C() ";}
  virtual void g() const override {cout << "C::g ";}
  virtual void m() {cout <<"C::m "; g(); j();}
  void k() override {cout <<"C::k "; B::n();}
  B& n() override {cout <<"C::n "; return *this; }
};


class D: virtual public B {
public:
  D() {cout<<"D() ";}
  ~D(){ cout<<"~D() ";}
  virtual void g(){cout <<"D::g ";}
  const B* j() {cout <<"D::j "; return this;}
  void k() const {cout <<"D::k "; k();}
  void m() {cout<<"D::m "; g(); j(); }
};

class E: public C, public D {
public:
  E() {cout<<"E() ";}
  ~E(){cout<<"~E() ";}
  virtual void g() const{cout << "E::g ";}
  const E* j(){cout<<"E::j "; return this;}
  void m() {cout <<"E::m "; g(); j();}
  D& n() final{cout <<"E::n "; return *this;}
};

class F: public E{
public:
  F() {cout<<"F() ";}
  ~F() {cout<<"~F() ";}
  F (const F& x): B(x) {cout<<"Fc ";}
  void k() {cout<<"F::k "; g();}
  void m() {cout<<"F::m "; j();}
};


int main() {
  B *p1 = new E();		// E()
  B *p2 = new C();		// C()
  B *p3 = new D();		// D()
  C *p4 = new E();		// E()
  const B *p5 = new D();	// D()
  const B *p6=new E();		// E()
  const B *p7=new F();		// F()
  F f;				// F()
  cout<<endl;

  cout<<"STAMPE"<<endl;		// STAMPE
  F x;cout<<endl;		// F()
  C *p=new F(f);cout<<endl;	// Fc
  p1->f();cout<<endl;		// B::f C::g D::j
  p1->m();cout<<endl;		// B::m C::g D::j
  // (p1->j())->k();		// NON COMPILA!! k() non costate!!
  // (dynamic_cast<const F*>(p1->j()))->g(); // compila, ma errore runtime non eiste F::g()
  p2->f();cout<<endl;			  // B::f C::g B::j
  p2->m();cout<<endl;			  // B::m C::g B::j
  (p2->j())->g();cout<<endl;		  // B::j C::g
  p3->f();cout<<endl;			  // B::f B::g D::j
  p3->k();cout<<endl;
  (p3->n()).m();cout<<endl;
  (dynamic_cast<D&>(p3->n())).g();cout<<endl;
  p4->f();cout<<endl;
  p4->k();cout<<endl;
  (p4->n()).m();cout<<endl;
  // (p5->n()).g();cout<<endl; // g() non costante
  // (dynamic_cast<E*>(p6))->j();cout<<endl; // p6 è costante ma cerca di castare a qualcosa di non costante 
  (dynamic_cast<C*>(const_cast<B*>(p7)))->k();cout<<endl;
  delete p7;cout<<endl;				
  cout<<"FINE STAMPE"<<endl;
}

/* Sto esercizio in realtà non posso farlo perchè l'ereditarietà multipla non l'abbiamo ancora vista, e neanche quella virtuale*/
