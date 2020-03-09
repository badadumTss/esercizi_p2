#include <iostream>

class A{
public:
  A& operator=(const A& a){ std::cout << "A::operator= "; return *this; }
};

class B: public A{
public:
  int x;
  B& operator=(const B& b) = default;
  B(int y=0):x(y){}
};

int main(){
  B b1(1), b2(2);

  std::cout << "b1: " << b1.x << std::endl << "b2: " << b2.x << std::endl;
  b1 = b2;
  std::cout << "fatto" << std::endl;
  std::cout << "b1: " << b1.x << std::endl << "b2: " << b2.x << std::endl;
  // b1 = b1 + b2; // non definito operator+ -> non c'è versione di default
  // b1 = b1 - b2; // non definito operator- -> non c'è versione di default
  return 0;
}

/*
  B& operator=(const B& b){
    A::operator=(b);
    x = b.x;
    y = b.y;
    ...
  }

  COMPORTAMENTO OPERATORE= DI DEFAULT:
  richiama sul sottoggetto (A::operator=(b)) con lo stesso oggetto passato per riferimento
  e poi copia campo per campo i propri membri con quelli dell'eggetto passato!!

 */
