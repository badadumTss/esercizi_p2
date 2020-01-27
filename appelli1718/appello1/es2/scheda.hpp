#ifndef SCHEDA_H
#define SCHEDA_H
#include "anomalia.hpp"

class Scheda{
protected:
  std::string numero;		// univoca, non serovono controlli
  float credito; 		// €
  float costoSMS; 		// €, >=0
public:
  Scheda(const std::string& n, const float& c, const float& cs):
    numero(n),
    credito(c > 0 ? cs : 0),
    costoSMS(cs > 0 ? cs : 0)
    {}
  virtual ~Scheda(){}
  virtual void telefonata(unsigned int) = 0; // constabilizza chiamata di k secondi, se non può permettersela -> Anomalia('v')
  virtual void connessione(double) = 0;	     // constabilizza traffico dati di k MB, se non può permetterselo -> Anomalia('d')
  virtual void messaggio(unsigned int n_messaggi){
    unsigned int costo_tot = n_messaggi * costoSMS;
    if(credito < costo_tot) {
      std::cerr << Anomalia('s') << std::endl;
    } else credito -= costo_tot;
    return;
  }
  virtual std::string getNum() const { return numero; }
  virtual float getCredito() const { return credito; }
};

#endif
