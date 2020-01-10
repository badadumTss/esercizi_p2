#include "telefonata.h"
#include <iostream>

telefonata::telefonata(const std::string& n, const orario& i, const orario& f):
    numero(n),
    inizio(i),
    fine(f >= i ? f : i)
    {
        if(f < i) std::cerr << "Orario di fine telefonata precendente all'orario iniziale: settato uguale" << std::endl;
    }

std::ostream& operator<<(std::ostream& os, const telefonata& t){
    return os << t.numero << ": " << t.inizio << " - " << t.fine;
}

bool telefonata::operator==(const telefonata& t) const{
    return numero == t.numero && 
           inizio == t.inizio && 
           fine == t.fine;
}

bool telefonata::operator!=(const telefonata& t) const{
    return !(*this == t);
}

std::istream& operator>>(telefonata& t){
    return *this >> telefonata.num >> inizio >> fine;
};