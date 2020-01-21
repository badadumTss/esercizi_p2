#include "../headers/rettangolo.hpp"

double rettangolo::area() const{
  return base*altezza;
}

double rettangolo::perimetro() const{
  return (2*base) + (2*altezza);
}
