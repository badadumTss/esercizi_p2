#include <iostream>
using namespace std;

class C {
public:
    int a[2];
    C(int x=0,int y=1) {
	a[0]=x; a[1]=y; cout << "C(" << a[0] << "," << a[1] << ") ";
    }
};

class D {
public:
    C c1;
    C *c2;
    C& cr;
    D(int x=0, int y=1) :c1(x,y), c2(&c1), cr(c1) { cout << "D() ";}
    D(const D& d) : cr(c1) { cout << "Dc ";}
    ~D() { cout << "~D ";}
};

class E {
public:
    static C cs;
};
C E::cs;

int main() {
    C c; cout << "UNO" << endl;
    C x(c); cout << x.a[0] << " " << x.a[1] << " DUE" << endl;
    D d=D(1,3); cout << "TRE" << endl;
    cout << d.c1.a[0] << ' ' << d.c1.a[1] << endl;
    E e; cout << "QUATTRO" << endl;
    return 0;
}
