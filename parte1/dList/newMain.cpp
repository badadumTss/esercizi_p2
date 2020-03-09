#include<iostream>

template<class T>
class dList{

  class nodo{
  public:
    T info;
    nodo *next, *prev;
    nodo(const T& t, nodo *p=nullptr, nodo *n=nullptr):info(t),prev(p),next(n){};
    ~nodo(){ delete next; };
  } *last, *first;

  static nodo* copy(nodo* n, nodo*& last){
    if(!n){
      last = nullptr;
      return nullptr;
    }
    nodo *succ = new nodo(n->info),
         *prev = succ,
         *start = succ;
    while(n->next){
      succ = new nodo(n->next->info,prev);
      prev->next = succ;
      n = n->next;
      prev = prev->next;
    }
    last = succ;
    return start;
  }

  static bool isLess(nodo* left, nodo* right){
    if(!left && !right) return false;
    if(!left) return true;
    if(!right) return false;
    if(left->info > right->info) return false;
    return left->info < right->info || isLess(left->next,right->next);
  }
  
public:
  dList():first(nullptr),last(nullptr){std::cout << "Chiamato" <<std::endl;};
  ~dList(){ delete first; };
  dList(const dList& d):first(copy(d.first,last)){};

  dList& operator=(const dList& d){
    delete first;
    first = copy(d.first,last);
    return *this;
  }

  void insertFront(const T& t){
    if(first){
      first = new nodo(t,nullptr,first);
      first->next->prev = first;
    }
    else first = last = new nodo(t);
  }

  void insertBack(const T& t){
    if(last){
      last = new nodo(t,last);
      last->prev->next = last;
    }
    else first = last = new nodo(t);
  }

  dList(int k, const T& t):first(nullptr),last(nullptr){
    for(int i=0; i<k; ++i)
      insertFront(t);
  }

  bool operator<(const dList& right){
    return isLess(first,right.first);
  }

  class constIterator{
    friend class dList<T>;
    nodo* ptr;
    bool pastTheEnd;
    constIterator(nodo* n,bool pte=false):ptr(n),pastTheEnd(pte){};
  public:
    constIterator():ptr(nullptr),pastTheEnd(false){};
    const T& operator*(){
      return ptr->info;
    }

    const T* operator->(){
      return &(ptr->info);
    }

    constIterator& operator++(){
      if(ptr){
	if(!pastTheEnd){
	  if(ptr->next) ptr = ptr->next;
	  else {
	    ptr++; pastTheEnd = true;
	  }
	}
      }	
      return *this;
    }

    constIterator& operator--(){
      if(ptr){
	if(pastTheEnd){
	  --ptr; pastTheEnd = false;
	} else {
	  ptr = ptr->prev;
	}
      }
      return *this;
    }

    bool operator==(const constIterator& right){
      return ptr == right.ptr;
    }

    bool operator!=(const constIterator& right){
      return ptr != right.ptr;
    }
  };

  constIterator end() const{
    if(last) return constIterator(last+1,true);
    else return nullptr;
  }

  constIterator begin() const{
    return constIterator(first);
  }
};

int main(){
  dList<char> parola;
  parola.insertBack('D');
  parola.insertBack('o');
  parola.insertBack('g');
  parola.insertBack('h');
  parola.insertBack('e');
  parola.insertBack(' ');
  parola.insertBack('n');
  parola.insertBack('e');
  parola.insertBack('l');
  parola.insertBack(' ');
  parola.insertBack('c');
  parola.insertBack('u');
  parola.insertBack('l');
  parola.insertBack('o');
  for(dList<char>::constIterator i = parola.begin(); i != parola.end(); ++i)
    std::cout << *i;
  std::cout << std::endl;
  return 0;
}
    
    
    
    

