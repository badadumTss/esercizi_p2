#ifndef SMART_LIST
#define SMART_LIST

template <class T>
class list{
  class nodo;
  class smartP{
    nodo* ptr;
  public:
    smartP(nodo* node = nullptr):ptr(node){ if(ptr) ++(ptr->ref); }
    smartP(const smartP& sp):ptr(sp.ptr){ if(ptr) ++(ptr->ref); }
    ~smartP(){ if(ptr) if(!(--(ptr->ref))) delete ptr; }
    nodo& operator*() const { return *ptr; }
    nodo* operator->() const { return ptr; }
    smartP& operator=(const smartP& sp){
      if(this != &sp){
	nodo* to_delete = ptr;
	ptr = sp.ptr;
	if(ptr) ++(ptr->ref);
	if(to_delete && !(--(to_delete->ref))) delete to_delete;
      }
      return *this;
    }
    operator void*() const { return ptr; }
  };

  smartP first, last;
  
  class nodo{
  public:
    T info;
    smartP next;
    unsigned int ref;
    nodo():ref(0){}
    nodo(const T& val, const smartP& _next = smartP()):info(val),next(_next),ref(0){}
    // giusto che costruiscano con ref=0, gli smartP si occupano dei riferimenti
  };

public:
  list():first(nullptr),last(nullptr){}
  // ~list(){} // distruttore dovrebbe essere ben formato in partenza!!
  // se qualcos'altro sta puntando alla lista formata non fa dangling, e se nulla la sta puntando allora elimina
  // i vari campi dati nell'ordine di apparizione: elimina first che è uno smartP, che dato il suo distruttore
  // ridefinito elimina a cascata tutta la lista o fermandosi al primo nodo puntato da qualcosa!! (tutta la lista
  // in pratica in realtà dato che nessuno dovrebbe poter accedere agli smartP all'esterno)
  void push_back(const T& obj){
    if(first == nullptr){
      first = smartP(new nodo(obj));
      last = first;
    } else {
      last->next = smartP(new nodo(obj));
      last = last->next;
    }
  }
  T pop(){
    T info = first->info;
    // smartP old = first;
    first = first->next;
    if (first == nullptr) last = last->next;
    return info; // tutto gestito da smartP!!
  }

  class const_iterator{
    friend class list<T>;
    smartP ptr;
    bool past_the_end;
    const_iterator(const smartP& _ptr, bool pte = false):ptr(_ptr),past_the_end(pte){}
    // copia di default dovrebbe andare bene, chiama costruttore di copia sui vari campi, quindi anche su ptr
    // anche distruttore di default!!
  public:
    const_iterator& operator++() {
      if(ptr && ptr->next != nullptr){
	ptr = ptr->next;
      } else if (ptr) past_the_end = true;
      return *this;
    }
    const T& operator*() const { return ptr->info; }
    const T* operator->() const { return &(ptr->info); }
    // const T* significa che l'iteratore NON PUò MODIFICARE L'OGGETTO PUNTATO, CHE è GIUSTO!!!
    bool operator==(const const_iterator& op){
      return past_the_end == op.past_the_end && ptr == op.ptr;
    }
    bool operator!=(const const_iterator& op){
      return past_the_end != op.past_the_end || ptr != op.ptr;
    }
  };

  const_iterator begin(){
    return const_iterator(first);
  }
  const_iterator end(){
    return const_iterator(last,true);
  }
};

#endif
