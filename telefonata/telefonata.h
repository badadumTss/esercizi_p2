#ifndef TELEFONATA_H
#define TELEFONATA_H

#include "../orario/orario.h"
#include <iostream> 
#include <string>

class telefonata{
    orario inizio, fine;
    std::string numero;
public:
    friend std::ostream& operator<<(std::ostream&, const telefonata&);
    friend std::istream& operator>>(telefonata&);
    telefonata(const std::string& = "", const orario& = orario(),const orario& = orario());
    bool operator==(const telefonata&) const;
    bool operator!=(const telefonata&) const;
};

#endif