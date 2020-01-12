namespace ns {
    class C {
    private:
	friend int f();
	int x;
    public:
	C(int n=0) : x(n) {}
    };

    int f() {
	ns::C c;
	return c.x;
    }

}

int main() {
    ns::f();
}
