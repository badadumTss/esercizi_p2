#ifndef VETTORE_H
#define VETTORE_H

#include <iostream>

class vettore{
    int *a;
    unsigned int _size;
    static int* copy(const vettore&);
public:
    vettore(unsigned int = 0, int = 0);
    vettore(const vettore&);
    ~vettore();

    unsigned int size() const;
    vettore& append(const vettore&);

    vettore& operator=(const vettore&);
    int& operator[](int) const;
};

vettore operator+(const vettore& ,const vettore&);
std::ostream& operator<<(std::ostream&, const vettore&);

#endif
