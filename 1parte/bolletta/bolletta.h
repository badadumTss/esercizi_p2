#ifndef BOLLETTA_H
#define BOLLETTA_H

#include "../telefonata/telefonata.h"

class Bolletta{

    class nodo{
    public:
        telefonata info;
        nodo* next;
        nodo(const telefonata&, nodo* = nullptr);
        ~nodo();
        nodo(const nodo&);
    } *inizio;

public:
    Bolletta();
    Bolletta(const telefonata&);
    ~Bolletta();

    class iteratore{
        Bolletta::nodo* ptr = nullptr;
    public:
        iteratore& operator++();
        iteratore operator++(int);
        bool operator==(const iteratore&) const;
        bool operator!=(const iteratore&) const;
        telefonata* operator->() const;
        friend Bolletta;
    };
    
    iteratore begin() const;
    iteratore end() const;

    Bolletta& append(const telefonata&);
    Bolletta& remove(const telefonata&);
    int size() const;
    bool isEmpty() const;
    static void empty(Bolletta&);
    
    Bolletta& operator=(const Bolletta&);
    telefonata& operator[](const iteratore&) const;
};

std::ostream& operator<<(std::ostream&, const Bolletta&);

#endif