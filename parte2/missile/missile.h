#ifndef MISSILE_H
#define MISSILE_H
#include<math.h>
#include "cono.h"
#include "cilindro.h"

class missile: public cono, public cilindro{
protected:
public:

	missile(double raggio, double altezza_cil, double altezza_con):
		formaConCerchio(raggio),
		cono(altezza_con),
		cilindro(altezza_cil){}
	
	double superficie_laterale() const{
		return (cilindro::superficie_laterale()+
				cono::superficie_laterale());
	}

	double volume() const{
		return (cilindro::volume() + cono::volume());
	}

	double area_tot() const{
		return superficie_laterale() + area_base();
	}
};

#endif /* MISSILE_H */
