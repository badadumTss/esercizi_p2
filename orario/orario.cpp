#include "orario.h"

orario::orario(int o, int m, int s){
    sec = (o*3600 + m*60 + s) % 86400;
    return;
}

int orario::Ore() const{
    return sec / 3600;
}

int orario::Min() const{
    return (sec % 3600) / 60;
}

int orario::Sec() const{
    return (sec % 3600) % 60;
}

void orario::AvantiUnOra(){
    sec += 3600;
}

orario orario::UnOraPiuTardi() const{
    orario temp(*this);
    temp.AvantiUnOra();
    return temp;
}

std::ostream& operator<<(std::ostream& out, const orario& ora){
    out << ora.Ore() << ":" << ora.Min() << ":" << ora.Sec();
    return out;
}

orario orario::operator+(const orario& right) const{
    orario tmp;
    tmp.sec = (sec + right.sec) % 86400;
    return tmp;
}

bool orario::operator==(const orario& dx) const{
    return sec == dx.sec;
}

bool orario::operator<(const orario& dx) const{
    return sec < dx.sec;
}

bool orario::operator>(const orario& dx) const{
    return sec > dx.sec;
}

bool orario::operator<=(const orario& dx) const{
    return sec <= dx.sec;
}

bool orario::operator>=(const orario& dx) const{
    return sec >= dx.sec;
}

std::istream& operator>>(orario& o){
    int input;
    *this >> input;
    o.sec = (input*3600);
    *this >> input;
    o.sec += (input*60);
    *this >> input;
    o.sec += input;
    o.sec = o.sec % 86400;
    return *this;
}