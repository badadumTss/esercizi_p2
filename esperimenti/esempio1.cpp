#include <iostream>

class B{
public:
	virtual void m(int x=0) { std::cout << "B::m "; }
};

class D: public B{
public:
	void m(int x) override { std::cout  << "D::m "; }
	virtual void m() {std::cout << "D::m() "; }
};

int main(){
	B* p = new D();
	D* q = new D();
	p->m(1);
	p->m();
	q->m(1);
	q->m(); // entrano in conflitto questa e virtual void m(int x=0) overridata
	return 0;
}
