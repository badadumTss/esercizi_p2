#ifndef SMART_P_H
#define SMART_P_H
#include <iostream>

template<class T>
class SmartP{

  T* ptr;
  
public:
  SmartP(const T* t = nullptr):ptr(t ? new T(*t) : nullptr){}
  SmartP(const SmartP& sp):ptr(new T(*sp)){}
  ~SmartP(){ delete ptr; }
  const SmartP& operator=(const SmartP& p){
    if(this != &p){
      delete ptr;
      ptr = new T(*p);
    }
    return *this;
  } // assegnazione profonda
  bool operator==(const SmartP& p) const{
    return ptr == p.ptr;
  }
  bool operator!=(const SmartP& p) const{
    return !(*this == p);
  }
  T& operator*() const{
    return *ptr;
  }
  T* operator->() const{
    return ptr;
  }
};

#endif
