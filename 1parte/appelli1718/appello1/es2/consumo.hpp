#ifndef CONSUMO_H
#define CONSUMO_H
#include "scheda.hpp"

class Consumo: public Scheda{
  float costo_telefonata_sec, costo_dati_mb;
public:
  Consumo(std::string num = "0", float credito = 0, float csms = 0.2, float cts = 0.01, float cdmb = 0.1):
    Scheda::Scheda(num, credito, csms),
    costo_telefonata_sec(cts > 0 ? cts : 0),
    costo_dati_mb(cdmb > 0 ? cdmb : 0)
    {}
  void telefonata(unsigned int sec){
    float costo = costo_telefonata_sec * sec;
    if (costo < credito)
      credito -= costo;
    else std::cout << Anomalia('v') << std::endl;
  }
  void connessione(double mb){
    float costo = costo_dati_mb * mb;
    if (costo < credito)
      credito -= costo;
    else std::cout << Anomalia('d') << std::endl;
  }
};
#endif
