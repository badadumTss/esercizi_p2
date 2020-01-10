#include "vettore.h"
#include <iostream>

int main(){
    vettore uno(10,1);
    vettore due(2,2);
    vettore tre(5,6);

    std::cout << uno << std::endl << due << std::endl << tre << std::endl;

    vettore quattro(due);
    vettore cinque = due;

    tre = uno;

    cinque = quattro + tre;

    std::cout << uno << std::endl << due << std::endl << tre << std::endl << quattro << std::endl << cinque << std::endl;
    return 0;
}