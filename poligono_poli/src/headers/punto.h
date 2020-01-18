#ifndef PUNTO_H
#define PUNTO_H

class punto{
    double x, y, z;
public:
    /* Attenzione che questo vuol dire int => punto */
    punto(double _x = 0, double _y = 0, double _z = 0):
	x(_x),
	y(_y),
	z(_z);
    static double lung(const punto&, const punto&);
};

#endif
