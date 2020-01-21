#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.hpp"

class triangolo: public poligono{
  double l1, l2, l3;
public:
  /* Attenzione che così il costrutore non checka la dimensioni dell'array*/
  triangolo(punto* pts):
    poligono(3, pts)
    l1(punto::lung(pts[0],pts[1])),
    l2(punto::lung(pts[1],pts[2])),
    l3(punto::lung(pts[2],pts[0]))
    {}
  double area() const;
  double perimetro() const;
}

#endif
