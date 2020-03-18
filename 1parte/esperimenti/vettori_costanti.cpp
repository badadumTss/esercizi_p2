/* Si può costruire vettori di oggetti costanti? scopriamolo */
#include <iostream>
#include <vector> // vector come potrebbe essere qualsiasi altro contenitore templatizzato della stdlib
class A{};

int main(){
  // std::vector<const A> vettore; // non funziona!! must have a non-constant, non-volatile value type
  // std::vector<A&> vettore; // allo stesso modo, tutta una serie di errori sul fatto che poi non è assegnabile
  return 0;
}
