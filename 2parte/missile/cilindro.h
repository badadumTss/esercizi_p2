#ifndef CILINDRO_H
#define CILINDRO_H
#include "formaConCerchio.h"

class cilindro: virtual public formaConCerchio{
protected:
	double altezza;
public:

	cilindro(double h=0, double b=0):
		formaConCerchio(b),
		altezza(h){}
	
	double superficie_laterale() const {
		return M_PI*2*raggio*altezza;
	}

	double volume() const {
		return area_base() * altezza;
	}
};

#endif /* CILINDRO_H */
