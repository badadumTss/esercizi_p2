#ifndef MENSILE_H
#define MENSILE_H
#include "scheda.hpp"

class Mensile: public Scheda{
  unsigned int telefonate_incluse, telefonate_effettuate;
  double mb_inclusi, mb_usati;
  double costo_abbonamento;
public:
  Mensile():
    Scheda::Scheda("0", 0, 0.1),
    telefonate_incluse(60000),
    mb_inclusi(2096),
    telefonate_effettuate(0),
    mb_usati(0)
    {}
  void telefonata(unsigned int sec){
    if (telefonate_incluse < telefonate_effettuate + sec)
      telefonate_effettuate += sec;
    else
      std::cout << Anomalia('v') << std::endl;
  }
  void connessione(double c){
    if(mb_inclusi > mb_usati + c)
      mb_usati += c;
    else std::cout << Anomalia('d') << std::endl;
  }
};
#endif
