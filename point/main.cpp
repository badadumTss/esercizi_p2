#include "point.h"
#include <iostream>

int main(){
    Point a, b(2), c(3,1,9);
    c.negate();
    std::cout << a << std::endl << b.norm() << std::endl << c << std::endl;
    return 0;
}