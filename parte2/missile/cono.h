#ifndef CONO_H
#define CONO_H
#include <math.h>
#include "formaConCerchio.h"

class cono: virtual public formaConCerchio{
protected:
	double altezza;
public:

	cono(double h=0, double b=0):
		formaConCerchio(b),
		altezza(h){}
	
	virtual double apotema() const{
		return sqrt(raggio*raggio + altezza*altezza);
	}
	
	double superficie_laterale() const{
		return M_PI*raggio*apotema();
	}

	double volume() const{
		return (M_PI*raggio*altezza)/3;
	}
};

#endif /* CONO_H */
