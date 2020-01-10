#ifndef ORARIO_H
#define ORARIO_H
#include<iostream>

class orario
{
private:
    int sec;
public:
    orario(int=0,int=0,int=0);
    static const int sec_ora = 3600;

    int Sec() const;
    int Min() const;
    int Ore() const;

    orario UnOraPiuTardi() const;
    void AvantiUnOra();

    orario operator+(const orario&) const;
    bool operator==(const orario&) const;
    bool operator<(const orario&) const;
    bool operator>(const orario&) const;
    bool operator<=(const orario&) const;
    bool operator>=(const orario&) const;
    friend std::istream& operator>>(orario&);
};

std::ostream& operator<<(std::ostream&, const orario&);


#endif