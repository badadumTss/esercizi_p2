#include<iostream>

class A{
  int x;
public:
  A(int y=0):x(y){ std::cout << "A(" << x << ") "; }
  ~A(){ std::cout << "~A(" << x << ") "; }
  A(const A& a):x(a.x){ std::cout << "A(const A&) "; } 
};

class C{
public:
  ~C(){ std::cout << "~C() "; }
};

class B: public A{
  C x;
public:
  B(int y=0):A(y+1){ std::cout << "B() "; }
  ~B(){ std::cout << "~B() "; }
  B(const B& a):A(a),x(a.x){ std::cout << "B(const B&) "; } 
};

int main(){
  A a = A();			// A(0) A(const A&) ~A(0)
  std::cout << std::endl;
  B b1(2);			// A(3) B(2)
  std::cout << std::endl;
  B b2 = B(3);			// A(4) B(3) A(const A&) B(const& B) ~B(3) ~A(2)
  std::cout << std::endl;
  // ~B(3) ~A(4) ~B(2) ~A(3) ~A(0)
  std::cout << std::endl;
  return 0;
}
