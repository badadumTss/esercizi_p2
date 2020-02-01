#ifndef ABS_H
#define ABS_H
#include <typeinfo>
class Abs{
public:
  virtual ~Abs() = 0;
};

template <class T1, class T2>
bool Fun(T1* ptr, T2& ref){
  return (
    typeid(T1) == typeid(T2) &&
    typeid(*ptr) == typeid(ref) && // QUESTA SERVE PERCHè ptr potrebbe puntare a un sottotipo di T1 diverso da T1!!!!
    // Mai fidarsi dei puntatori
    dynamic_cast<Abs*>(ptr)
    )
}
#endif
