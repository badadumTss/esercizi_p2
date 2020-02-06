/* Sta roba era nell'esame e voglio verificare che funzioni */

class B{};

class D: public B{};

class F: public D{
  int v1;
  int* v2;
  int& v3;
public:
  F():v3(v1){};
  F(const F& obj):D::D(obj),v1(obj.v1),v2(obj.v2),v3(obj.v3){} /* Funzionaaaaaaa Si!! ance disambiguare va bene */
};

int main(){
  F f1;
  F f2(f1);
  return 0;
}
