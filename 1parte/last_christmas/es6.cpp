
#include<iostream>
using namespace std;
class C {
public:
    int number;
    C(int n=1) : number(n) { cout << "C(" << number << ") "; }
    ~C() { cout << " ~C(" << number << ") "; }
    C& operator=(const C& c) { number=c.number; cout << "operator=(" << number << ") "; return *this; }
};

int F(C c) {return c.number;}

int main() {
    C *c=new C; cout << "UNO" << endl;
    C d; d=*c; cout << "DUE" << endl;
    int x=F(d); cout << "TRE" << endl;
    int y=F(F(d)); cout << "QUATTRO" << endl;
}
