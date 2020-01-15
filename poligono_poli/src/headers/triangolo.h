#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"

class triangolo: public poligono{

    point* arr(const point& p1, const point& p2, const point& p3){
	point *tmp = new point[3];
	tmp[0] = p1;
	tmp[1] = p2;
	tmp[2] = p3;
	return tmp;
    }
    
public:
    triangolo(const point& p1, const point& p2, const point& p3):poligono(3, arr(p1,p2,p3)){}
    
    double area() const;
}

#endif
