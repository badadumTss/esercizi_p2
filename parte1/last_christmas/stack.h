#ifndef STACK_H
#define STACK_H

#include<iostream>

template<class T=char, int num=100>
class stack{
    class nodo{
    public:
	T info;
	nodo* next;
	
	nodo(const T& x, nodo* y=nullptr):info(x), next(y){}
	~nodo(){ delete next; }
	
    } *_first, *_last;
    
    unsigned int nElementi;
  
    nodo* last(nodo* n){
	if(!n) return nullptr;
	if(n->next) return last(n->next);
	return n;
    }

    nodo* copy(nodo* first){
	if(!first) return nullptr;
	return new nodo(first->info, copy(first->next));
    }

    bool node_search(const T& t, nodo* n){
	if(!n) return false;
	if(n->info == t) return true;
	return node_search(t, n->next);
    }

    bool isEqual(nodo* n1, nodo* n2){
	if (!n1){
	    if(!n2) return true;
	    return false;
	}
	if (!n2) return false;
	return ((n1->info == n2->info) && isEqual(n1->next,n2->next));
    }
  
public:
    stack():
	_first(nullptr),
	_last(nullptr),
	nElementi(0)
	{}

    stack(const T& t, unsigned int k=1):
	_first(nullptr),
	_last(nullptr),
	nElementi(0)
	{
	    for(int i=0; i<k; i++){
		this->push(t);
	    }
	}

    stack(const stack& s):
	_first(copy(s._first)),
	_last(last(_first)),
	nElementi(s.nElementi)
	{}

    ~stack(){ delete _first; }

    bool isEmpty(){
	return nElementi == 0;
    }
    bool isFUll(){
	return nElementi == num;
    }
    unsigned int size(){
	return nElementi;
    }
    stack& operator=(const stack& s){
	delete _first;
	_first = copy(s._first);
	_last = last(_first);
    }

    operator int() const{
	return nElementi;
    }

    //Push in testa
    bool push(const T& t){
	if(nElementi<num){
	    _first = new nodo(t, _first);
	    if(!_last) _last = _first;
	    ++nElementi;
	    return true;
	} else { return false; }
    }

    //Pop del primo elemento
    void pop(){
	if(nElementi){
	    --nElementi;
	    nodo* old = _first;
	    _first = _first->next;
	    old->next = nullptr;
	    delete old;
	    if(!_first) _last = nullptr;
	}
    }

    //Top nello stack, se vuoto undefined behaviour
    T top(){
	return _first->info;
    }

    //Bottom dello stack, se vuoto undefined behavior;
    T bottom(){
	return _last->info;
    }

    bool search(T& t){
	return node_search(t,_first);
    }

    //flusha tutto
    void flush(){
	delete _first;
	_first = _last = nullptr;
	nElementi = 0;
    }

    //somma
    stack operator+(const stack s2){
	stack s1(*this);
	s2._last->next = s1._first;
	s2._last = s1._last;
	return s2;
    }

    // operatore di uguaglianza
    bool operator==(const stack& s){
	return isEqual(_first,s._first);
    }

    //Classe iteratore per fare stampa migliore?
};

// dato che non ho iteratori, lo stack lo prendo di copia e faccio pop
template<class T,int num=100>
std::ostream& operator<<(std::ostream& os, stack<T,num> t){
    while(!t.isEmpty()){
	os << t.top() << ' ';
	t.pop();
    }
    return os;
}


int main(){
    stack<int> proc_id(10,30);
    stack<char,10> str('q', 8);

    proc_id.push(500);
    str.push('t');
    str.push('t');
    str.push('t');

    std::cout << "Proc_id: " << proc_id << std::endl;
    std::cout << "str: " << str << std::endl;
}

#endif
