#include "bolletta.h"
#include <iostream>

Bolletta::nodo::nodo(const telefonata& t, nodo* n):info(t),next(n){}
Bolletta::nodo::~nodo(){delete next;}
Bolletta::nodo::nodo(const nodo& n):info(n.info),next(n.next ? new nodo(*(n.next)) : nullptr){}

Bolletta::Bolletta():inizio(nullptr){}

Bolletta::Bolletta(const telefonata& t):inizio(new nodo(t)){}

Bolletta::~Bolletta(){
    delete inizio;
}

Bolletta& Bolletta::append(const telefonata& t){
    nodo* tmp = inizio;
    inizio = new nodo(t);
    inizio->next = tmp;
    return *this;
}

Bolletta& Bolletta::remove(const telefonata& t){
    if(inizio){
        nodo* prec = inizio, *current = inizio->next;
        while (current && current->info != t)
        {
            current = current->next;
            prec = prec->next;
        }
        if(current){
            prec->next = current->next;
            current->next = nullptr;
            delete current;
        }    
    }
    return *this;
}

int Bolletta::size() const{
    int count(0);
    nodo* ptr = inizio;
    while(ptr){
        count++;
        ptr = ptr->next;
    }
    return count;
}

void Bolletta::empty(Bolletta& b){
    delete b.inizio;
    b.inizio = nullptr;
}

bool Bolletta::isEmpty() const{
    return inizio;
}

Bolletta::iteratore& Bolletta::iteratore::operator++(){
    if(ptr) ptr = ptr->next;
    return *this;
}

Bolletta::iteratore Bolletta::iteratore::operator++(int){
    iteratore aux = *this;
    if(ptr) ptr = ptr->next;
    return aux;
}

bool Bolletta::iteratore::operator==(const iteratore& i) const{
    return ptr == i.ptr;
}

bool Bolletta::iteratore::operator!=(const iteratore& i) const{
    return ptr != i.ptr;
}

Bolletta::iteratore Bolletta::begin() const{
    iteratore aux;
    aux.ptr = inizio;
    return aux;
}

Bolletta::iteratore Bolletta::end() const{
    iteratore aux;
    aux.ptr = nullptr;
    return aux;
}

telefonata& Bolletta::operator[](const iteratore& it) const{
    return it.ptr -> info;
}

telefonata* Bolletta::iteratore::operator->() const{
    return &(ptr->info);
}

std::ostream& operator<<(std::ostream& os, const Bolletta& b){
    for(Bolletta::iteratore it = b.begin(); it != b.end(); ++it){
        os << b[it] << std::endl;
    }
    return os;
}

Bolletta& Bolletta::operator=(const Bolletta& b){
    delete inizio;
    inizio = new nodo(*(b.inizio));
    return *this;
}