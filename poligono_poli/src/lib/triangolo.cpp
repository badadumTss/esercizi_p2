#include "../headers/triangolo.h"
#include <math.h>

double triangolo::perimetro() const{
    return (l1+l2+l3);
}

double triangolo::area() const{
    duble smp = (perimetro() / 2);
    return (sqrt(smp*(smp - l1)*(smp - l2)*(smp - l3)));
}
