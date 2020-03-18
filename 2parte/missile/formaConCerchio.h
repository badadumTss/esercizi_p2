#ifndef FORMACONCERCHIO_H
#define FORMACONCERCHIO_H
#include <math.h>

class formaConCerchio{
protected:
	double raggio;
	double base() const { return 2*M_PI*raggio; }
	double area_base() const { return M_PI*raggio*raggio; }
public:
	formaConCerchio(double r=0):raggio(r>0 ? r : 0){}
	virtual ~formaConCerchio() = default;
	virtual double superficie_laterale() const = 0;
	virtual double volume() const = 0;
};

#endif /* FORMACONCERCHIO_H */
