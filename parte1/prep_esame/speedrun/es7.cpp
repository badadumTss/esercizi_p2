class A{
public:
  virtual ~A() = default;
};

class B: public A{
public:
  ~B() = 0;
};

class C: public B{};

class D{
protected:
  D() = default;
};

class E: public D{
public:
  E& operator=(const E& e){ D::operator=(e); return *this; }
};  
