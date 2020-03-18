#include <iostream>
using namespace std;

template<class T>
class SmartP{
  T* ptr;
  T* copy(const T* p){
    return (p ? new T(*p) : nullptr);
  }
public:
  SmartP(const T* p = nullptr):ptr(copy(p)){}
  SmartP(const SmartP& p):ptr(copy(p.ptr)){}
  ~SmartP(){ delete ptr; }
  SmartP& operator=(const SmartP& p){
    if(this != &p){
      delete ptr;
      ptr = copy(p.ptr);
    }
    return *this;
  }

  T& operator*(){
    // giustamente se ptr è nullptr -> undefined behavior -> errore runtime
    return *ptr;
  }

  T* operator->(){
    // anche in questo caso sta all'utilizzatore sapere se ptr punta a qualcosa in memo o no, nel caso errore runtime
    return ptr;
  }

  bool operator==(const SmartP& p){
    return ptr == p.ptr;
  }

  bool operator!=(const SmartP& p){
    return !(*this == p);
  }
};

class C {
public:
  int* p;
  C(): p(new int(5)) {}
//  ~C(){ delete p; }
};
int main() {
  const int a=1; const int* p=&a;
  SmartP<int> r; SmartP<int> s(&a); SmartP<int> t(s);
  cout << *s << " " << *t << " " << *p << endl; // 1 1 1
  *s=2; *t=3;
  cout << *s << " " << *t << " " << *p << endl; // 2 3 1
  r=t; *r=4;
  cout << *r << " " << *s << " " << *t << " " << *p << endl; // 4 2 3 1
  cout << (s == t) << " " << (s != p) << endl; // 0 1
  C c; SmartP<C> x(&c);
  cout << *(c.p) << " " << *(x->p) << endl; // 5 5
  *(c.p)=6;
  cout << *(c.p) << " " << *(x->p) << endl; // 6 6
  SmartP<C>* q = new SmartP<C>(&c);
  delete q;
  cout << *(x->p) << endl; // 6
}
// Giusto che ci sia leak di memoria, deriva dal fatto che C è fatta da cani
