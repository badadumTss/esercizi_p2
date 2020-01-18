#ifndef POLIGONO_H
#define POLIGONO_H
#include "punto.h"

class poligono{
    
    unsigned int nVert;
    punto *vert;
    static punto* copia(punto*,unsigned int);
    
public:
    poligono(unsigned int n, punto* v):
	nVert(n),
	vert(copia(v,n));
    virtual ~poligono(){ delete[] vert };
    virtual double perimetro() const;
    virtual double area() const = 0;
}
    
#endif
