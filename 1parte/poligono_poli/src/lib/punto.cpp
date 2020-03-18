#include "../headers/punto.h"
#include <math.h>

double point::lung(const point& p1, const point& p2){
    return sqrt((p1.x)*(p1.x) + (p1.y)*(p1.y) + (p1.z)*(p1.z));
}
