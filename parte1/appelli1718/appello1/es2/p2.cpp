#ifndef P2_H
#define P2_H
#include <list>
#include "consumo.hpp"
#include "mensile.hpp"

class P2{
  std::list<Scheda*> clienti;
  void clear_clienti(){
    for(std::list<Scheda*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      delete *it;
    }
    clienti.clear();
  }
  
public:
  
  ~P2(){
    for(std::list<Scheda*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it)
      delete (*it);
  }
  
  // suppongo he il numero per i clienti sia univoco
  Consumo* cambioPiano(const std::string& num){
    bool trovato = false;
    std::list<Scheda*>::iterator it = clienti.begin();
    for(; it != clienti.end(); ++it){
      trovato = ((*it)->getNum() == num);
    }
    if(dynamic_cast<Mensile*>(*it)){
      float credito = (*it)->getCredito();
      delete *it;
      *it = new Consumo(num,credito);
      return dynamic_cast<Consumo*>(*it);
    }
    return nullptr;
  }

  std::list<Consumo> rimuoviConsumoZero(){
    std::list<Consumo> to_return;
    std::list<Scheda*> new_clienti;
    for(std::list<Scheda*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      Consumo* ptr = dynamic_cast<Consumo*>(*it);
      // essendo credito float == false sse è 0
      if(ptr && !(ptr->getCredito())){
	to_return.push_back(*ptr);
      }
      else new_clienti.push_back(*it);
    }
    clear_clienti();
    clienti = new_clienti;
    return to_return;
  }

  double contabilizza() {
    double ding_ding_prima = 0;
    for(std::list<Scheda*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      ding_ding_prima += (*it)->getCredito();
    }

    for(std::list<Scheda*>::iterator it = clienti.begin(); it != clienti.end(); ++it){
      (*it)->telefonata(1);
      (*it)->connessione(1);
      (*it)->messaggio(1);
    }

    double ding_ding_dopo = 0;
    for(std::list<Scheda*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      ding_ding_dopo += (*it)->getCredito();
    }

    return ding_ding_dopo - ding_ding_prima;
  }
};
#endif
