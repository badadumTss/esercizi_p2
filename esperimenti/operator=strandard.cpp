#include <iostream>

class A{
public:
  A& operator=(const A& a){ std::cout << "A::operator=() "; return *this; }
};

class B: public A{
public:
  B& operator=(const B& b) = default;
};

int main(){
  A a;
  B b1, b2;
  b1 = b2;
  return 0;
}
