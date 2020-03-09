/*
C è un vettore di lungheza size per tutta la sua vita.
la multeplicità di ogni oggetto di tipo Multinfo al suo intenro
delimita quante "occorrenze" dell'oggetto T ci sono, tutte però
tenute come oggetto singolo

l'operatore [n] non fa accedere all'n-esimo oggetto 'logico' (nel
senso che se un oggetto ha multelpicità>1 => dovrebbe contare più
volte, e invece no)

FORSE ERA UN ES CHE ANDAVA FATTO CON ARRAY DELLA STL
 */
#ifndef CLASSE_C_H
#define CLASSE_C_H

#include<iostream>
template<class T, unsigned int size> class C;

template<class T, unsigned int size>
std::ostream& operator<<(std::ostream&, const C<T,size>&);

template<class T, unsigned int size>
class C{

    friend std::ostream& operator<< <T,size> (std::ostream&, const C<T,size>&);
    
    class MultiInfo{
    public:
	T info;
	unsigned int mult;
	MultiInfo():mult(0){}
	MultiInfo(const T& t, int k):info(t),mult(k>0 ? k : 0){}
	MultiInfo(const MultiInfo& m):info(m.info),mult(m.mult){}
    } *arr;
    
public:
    C(const T& t, int k=0):
	arr(new MultiInfo[size]){
	unsigned int m = (k>0 ? k : 0);
	for(int i=0; i<size; ++i){
	    arr[i] = MultiInfo(t,m);
	}
    }
    
    /* dato che è costruttore di copia, è lecito assuemere che 
       anche left abbia esattamente size elementi */
    C(const C& c):
	arr(new MultiInfo[size]){
	for(int i=0; i<size; ++i){
	    arr[i] = c.arr[i];
	}
    }

    ~C(){ delete arr; }

    const C& operator=(const C& right){
	delete arr;
	arr = copy(right.arr);
    }

    T* operator[] (int k) const{
	return &(arr[k].info);
    }

    int occorrenze(const T& t) const{
	int sum=0;
	for(int i=0; i<size; ++i){
	    if(arr[i].info == t) sum += arr[i].mult;
	}
	return sum;
    }
    
    bool operator==(const C& right) const{
	bool match = true;
	for(int i=0; match && i<size; ++i){
	    match = (arr[i].info == right.arr[i].info) && (arr[i].mult == right.arr[i].mult);
	}
	return match;
    }
};

template<class T, unsigned int size>
std::ostream& operator<<(std::ostream& os, const C<T,size>& array){
    for(int i=0; i<size; ++i){
	os << "Value: " << array.arr[i].info << std::endl;
	os << "Mult: " << array.arr[i].mult << std::endl;
    }
    return os;
}

#endif
