#include<iostream>
using namespace std;

class C {
private:
    int number;
public:
    C(int n=0) : number(n) { cout << "C(" << number << ") "; }
    ~C() { cout << " ~C "; }
    C(const C& c) : number(c.number) { cout << "Cc(" << number << ") "; }
    operator int() { cout << "int() "; return 3;}
};

int F(C c) {return c;}

int main() {
    C *c=new C; cout << "UNO" << endl;
    C d; cout << "DUE" << endl;
    int x=F(d); cout << "TRE" << endl;
    C e=F(d); cout << "QUATTRO" << endl;
}
