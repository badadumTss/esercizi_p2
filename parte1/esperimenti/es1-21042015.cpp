class C {
public:                      // 1
  int *const p;              // 2
  C(int a=0): p(new int(a))  // 3
  { }                        // 4
};
main() {
  C x(3);                    // 5
  C y;                       // 6
  x=y;                       // 7 è qui che non va, l'assegnazione di default sarebbe fallata
  /*
    C& C::operator=(const C& a){ p = a.p; }
    p non può essere assegnato!!
   */
  C z(y);                    // 8
}
