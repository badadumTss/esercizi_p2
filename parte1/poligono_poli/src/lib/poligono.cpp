#include "../headers/poligono.h"
#include <math>

double poligono::perimetro() const{
    double perim = 0;
    for(int i=0; i<nVert; ++i){
	punto& p1 = vert[i];
	punto& p2 = (i<(nVert-1) ? vert[i+1] : vert[0]);
	perim += punto::lung(p1,p2);
    }
    return perim;
}

punto* poligono::copia(punto* p, unsigned int n){
    punto* vect = new punto[n];
    for(int i=0; i<n; ++i){
	vect[i] = p[i];
    }
    return vect;
}
