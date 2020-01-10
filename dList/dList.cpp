#include<iostream>

template <class T>
class dList
{
  class nodo
  {
  public:
    T info;
    nodo* next, *prev;
    nodo(const T& t, nodo* p=nullptr, nodo* n=nullptr):next(n),prev(){};
    ~nodo(){ delete next;};
  } *last, *first;

  static nodo* copy(nodo* l, nodo*& last)
  {
    if(!l){
      last = nullptr;
      return nullptr;
    }
    nodo* start = new nodo(l->info);
    nodo* prec(start), *succ(start);
    while(l->next){
      succ = new nodo(l->next->info, prec);
      prec->next = succ;
      l = l->next;
      prec = prec->next;
    }
    last = succ;
    return start;
  }

  static isLess(nodo* l, nodo* r){
    if(!l && !r) return false;
    if(!l) return true;
    if(!r) return false;
    if(l->info > r->info) return false;
    return l->info < r->info || isLess(l->next, r->next); 
  }
  
  
public:
  dList():first(nullptr),last(){}
  ~dList(){ delete first; };
  dList& operator=(const dlist& l){
    delete first;
    first = copy(l.first,last);
  }
  dList(const dList& l):first(copy(l.first,last)){};
  void insertFront(const T& t){
    if(first){
      first->prev = new nodo(t,nullptr,first);
      first = first->prev;
    } else first = last = new nodo(t);
  }
  void insertBack(const T& t){
    if(last){
      last->next = new nodo(t,last);
      last = last->next;
    } else first = last = new nodo(t);
  }

  dList(int k, const T& t):first(nullptr),last(nullptr){
    for(int i=0; i<k; ++i)
      insertBack(t);
  }

  bool operator<(const dList& right){
    return isLess(first,right.first); 
  }

  class constIterator{
      friend class dList;
      nodo* ptr;
      bool pastTheEnd;
      constIterator(nodo* n, bool pte=false):ptr(n),pastTheEnd(pte){}
    public:
      constIterator():ptr(nullptr),pastTheEnd(false){};
      constIterator& operator=(const constIterator)
    //++;
    //--;
    //op*
    //op->
      constIterator& operator++(){
        if()
      }
  };
  end() //(pte)
  begin()
};

int main(){

  return 0;
}
