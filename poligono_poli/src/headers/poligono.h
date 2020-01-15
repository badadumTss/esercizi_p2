#ifndef POLIGONO_H
#define POLIGONO_H

class point{
    double x, y, z;
public:
    point();
    static double lung(const point&, const point&);
};

class poligono{
    unsigned int nVert;
    point *vert;
public:
    poligono(unsigned int, point* const);
    ~poligono();
    virtual double perimetro() const;	
}
    
#endif
