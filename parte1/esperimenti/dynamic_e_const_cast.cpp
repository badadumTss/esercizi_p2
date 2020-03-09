#include <iostream>

class A{
public:
  virtual void f() const { std::cout << "A::f "; return; }
  virtual void g() const { f(); }
};

class B: public A{
public:
  void f() const { std::cout << "B::f "; return; }
};

class C{
  int a;
public:
  void g() { std::cout << "C::g!! "; }
};

int main(){
  A* p1 = new B();
  A* p2 = new A();

  p1->f();
  p1->g();
// dynamic_cast<B*>(p2)->f(); 	// errore a run-time!! non risolvibile dal compilatore a compile-time
   
  /* 
     C* cast = dynamic_cast<C*>(p1);
     cast->g();			   // SEGFAULTA!! ma a compile time non da errori!! errore run-time
     // static_cast<C*>(p1)->g();  // Questo lo becca!!
     // La verità è che è UNDEFINED BEHAVIOR 
  */
  static_cast<B*>(p1)->g();

  std::cout << std::endl;
  return 0;
}
