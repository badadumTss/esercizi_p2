#ifndef CODA_H
#define CODA_H

#include<iostream>

template<class T=double>
class coda{
    class nodo{
    public:
	T info;
	nodo *next, *prev;
	nodo(const T& t, nodo* n1=nullptr, nodo* n2=nullptr):
	    info(t),
	    next(n1),
	    prev(n2)
	    {};
	
	~nodo(){ delete next; }
    } *first, *last;

    /* 
       CONST MANTRA: const dopo il ptr -> PUNTATORE costante, 
       NON OGGETTO PUNTATO COSTANTE 
    */
    bool confronta(nodo* const n1, nodo* const n2){
	if(!n1){
	    if(!n2) return true;
	    return false;
	}
	if(!n2) return false;
	return (n1->info == n2->info) && confronta(n1->next,n2->next);
    };
    
public:
    coda():
	first(nullptr),
	last(nullptr)
	{}
    
    coda(int k, const T& t):
	first(nullptr),
	last(nullptr)
	{
	    for(int i=0; i<k; i++){
		this->insert(t);
	    }
	}

    ~coda(){ delete first; }
    
    void insert(const T& t){
	if(first){
	    last->next = new nodo(t,nullptr,last);
	    last = last->next;
	} else {
	    first = last = new nodo(t);
	}
    }

    T removeNext(){
	nodo* to_delete = first;
	T to_return = first->info;
	first = first->next;
	to_delete->next = nullptr;
	delete to_delete;
	return to_return;
    }

    T* getNext(){
	if(first){
	    return &(first->info);
	} else
	    return nullptr;
    }
    
    bool operator<(const coda& c){
	return confronta(first, c.first);
    }

    coda& operator+(coda c){
	coda* c1 = new coda(*this);
	c1->last->next = c.first;
	c.first->prev = c1->last;
	c1->last = c.last;
	return *(c1);
    }

    class const_iterator{
	nodo* element;
	bool inBounds;
	const_iterator(nodo* n, bool ib=true):element(n),inBounds(ib){};
	friend class coda<T>;
    public:
	const_iterator():element(nullptr),inBounds(false){}
	const T& operator*(){
	    if(inBounds)
		return element->info;
	}
	const T* operator->(){
	    if(inBounds)
		return &(element->info);
	    else return nullptr;
	}
	const_iterator& operator++(){
	    if(!inBounds) return *this;
	    if(element->next) {
		element = element->next;
	    }
	    else{
		inBounds = false;
		element++;
	    }
	    return *this;
	}
	const_iterator& operator--(){
	    if(!inBounds){
		inBounds = true;
		element--;
	    } else {
		if(element == first){
		    //undefined behavior
		} else {
		    element = element->prev;
		}
	    }
	}
	bool operator!=(const const_iterator& i){
	    return i.element != element;
	}
    };
    const_iterator begin() const{
	return first;
    }
    const_iterator end() const{
	if(last) return const_iterator(last+1,false);
	return nullptr;
    }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const coda<T>& c){
    typename coda<T>::const_iterator iter = c.begin();
    for(; iter != c.end(); ++iter){
	os << *iter << ' ';
    }
    return os;
}
#endif

/* 
ATTENTO AI GCH E AI TYPENAME, servono a disambiguare nel contesto
*/
