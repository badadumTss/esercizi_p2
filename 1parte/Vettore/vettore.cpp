#include "vettore.h"

vettore::vettore(unsigned int s, int x):
	a(s ? new int[s] : nullptr),
	_size(s)
{
	for(unsigned int i=0; i<s; i++)
		a[i] = x;
}

vettore::vettore(const vettore& v):
	_size(v.size())
{
	a = copy(v);
}

vettore::~vettore(){
	delete[] a;
}

int* vettore::copy(const vettore& v){
	int *tmp = nullptr;
	if(v.a){
		tmp = new int[v.size()];
		for(unsigned int i=0; i<v.size(); i++)
			tmp[i] = v.a[i];
	}
	return tmp;
}

unsigned int vettore::size() const {return _size;}

vettore& vettore::operator=(const vettore& v){
	delete[] a;
	a = copy(v);
	_size = v.size();
	return *this;
}

int& vettore::operator[](int i) const{
	return a[i];
}

vettore operator+(const vettore& v1, const vettore& v2){
	vettore aux(v1.size() + v2.size());
	
	for(int i=0; i<(int)v1.size(); i++)
		aux[i] = v1[i];

	for(int i=0; i<(int)v2.size(); i++)
		aux[v1.size() + i] = v2[i];

	return aux;
} 

std::ostream& operator<<(std::ostream& os, const vettore& v){
	os << '(';
	for(int i=0; i<(int)v.size(); i++){
		os << v[i];
		if(i < (int)v.size()-1) os << ',';
	}
	return os << ')';
}
