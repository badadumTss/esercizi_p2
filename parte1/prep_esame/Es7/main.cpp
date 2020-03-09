class A{
public:
  virtual ~A(){};
};

class B: public A{
public:
  ~B() = 0;
};

class C: public B{};

class D{
public:
  virtual ~D() = 0;
};

class E: public D{
public:
  E& operator=(const E& right){
    D::operator=(right);
    return *this;
  }
};
