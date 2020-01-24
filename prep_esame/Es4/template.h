#include "Abs.h"
#include <typeinfo>

template <class T1, class T2>
bool Fun(T1* obj1, T2& obj2){
  if(typeid(T1) == typeid(T2) && typeid(*obj1) == typeid(obj2) && static_cast<Abs*>(T1)
/* typeid(*obj1) == typeid(obj2) serve perchè il tipo dinamico
   di obj1 potrebbe essere diverso dal suo tipo statico!!!!!! */
     return true;
  else return false;
}
