#include <iostream>

class A{
public:
  int x;
  A(){}
};

class B: public A{
public:
  int y;
  B(){}
};

void fun(A* a, B* b){
  B* b1 = static_cast<B*>(a);
  A* a1 = static_cast<A*>(b);
  std::cout << b1->y << std::endl; // UB!! che cavolo sto accedendo qui??, potrebbe esistere o no, potrei star accedendo a quello o ad altro idk UB!!
  std::cout << a1->x << std::endl; 
  std::cout << "Lol Works" << std::endl;
}

int main(){
  A* p1 = new A();
  B* p2 = new B();
  B* p3 = static_cast<B*>(p1);
  A* p4 = static_cast<A*>(p2);
  B* p5 = static_cast<B*>(p1);
  fun(p1,p2);
  fun(p2,p3);
  // fun(p3,p4);
  // fun(p4,p5);
  delete p1;
  delete p2;
  return 0;
}
