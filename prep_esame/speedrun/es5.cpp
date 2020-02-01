#include<iostream>
#include<typeinfo>
#include<vector>

using namespace std;

class B {public: virtual  ~B() {} };
class C: public B {};
class D: public B {};
class E: public C {};

int Fun(vector<B*> &v){
  int count = 0;
  for(vector<B*>::const_iterator it = v.begin(); it != v.end(); ++it){
    if(dynamic_cast<C*>(*it) && typeid(**it) != typeid(**(v.begin()))) ++count;
  }
  // typeid(**it) != typeid(v[0]) non è quello che chiede!
  // typeid(v[0]) è di tipo B* mentre **it è del tipo primitivo della classe (non un puntatore quindi)
  return count;
}

int main() {
  vector<B*> u, v, w;
  cout << Fun(u); // stampa 0
  B b; C c; D d; E e; B *p = &e, *q = &c;
  v.push_back(&c); v.push_back(&b); v.push_back(&d); v.push_back(&c);
  v.push_back(&e); v.push_back(p);
  cout << Fun(v); // stampa 2
  w.push_back(p); w.push_back(&d); w.push_back(q); w.push_back(&e);
  cout << Fun(w); // stampa 1
  cout << endl;
  return 0;
}
