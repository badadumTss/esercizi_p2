#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include "rettangolo.hpp"

class rettangolo: public poligono{
  double base, altezza;
public:
  rettangolo(punto* v):
    poligono(4,v),
    base(punto::lung(v[0],v[1])),
    altezza(punto::lung(v[1],v[2])){}
  double area() const;
  double perimetro() const;
};
#endi
