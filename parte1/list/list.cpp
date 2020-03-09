#include<iostream>

template <class T>
class list{
  
  class nodo{
  public:
    T info;
    nodo* next;
    nodo(const T& t, nodo* n=nullptr):info(t),next(n){};
    ~nodo(){ delete next; };
  } *first;

  static nodo* copia(nodo* n){
    if(n) return new nodo(n->info,copia(n->next));
    else return nullptr;
  }
    
public:
  list():first(nullptr){};
  list(const list& l):first(copia(l.first)){};
  ~list(){ delete first; };
  list& operator=(const list& l){
    delete first;
    first = copia(l.first);
    return *this;
  }

  class iterator{
    friend class list<T>;
  private:
    nodo* pointer;
    bool pte;
    iterator(nodo* n, bool p=false):pointer(n),pte(p){}
  public:
    iterator():pointer(nullptr),pte(false){};
    T& operator*(){
      return pointer->info;
    };
    T* operator->(){
      return &(pointer->info);
    };
    bool operator==(const iterator& i){
      return pointer == i.pointer;
    }
    bool operator!=(const iterator& i){
      return pointer != i.pointer;
    }
    iterator& operator++(){
      if(pointer) pointer = pointer->next;
      return *this;
    }

    bool hasNext(){ return pointer->next; };
  };

  iterator begin(){
    return first;
  }

  iterator end(){
    return nullptr;
  }

  list& push(const T& obj){
    first = new nodo(obj,first);
    return *this;
  }
  
  T pop(){
    T tmp_info = first->info;
    nodo* tmp_ptr = first;
    first = first->next;
    tmp_ptr->next = nullptr;
    delete tmp_ptr;
    return tmp_info;
  }
};

template <class T>
std::ostream& operator<< (std::ostream& os, list<T>& l){
  for(typename list<T>::iterator i = l.begin(); i != l.end(); ++i){
    os << *i;
    if(i.hasNext()) os << " -> ";
  }
  os << std::endl;
  return os;
}

int main(){
  list<int> interi;
  for(int i=0; i<10; ++i){
    interi.push(i);
  }
  std::cout << interi << std::endl;
  std::cout << interi.pop() << std::endl;
  std::cout << interi << std::endl;
  return 0;
}
