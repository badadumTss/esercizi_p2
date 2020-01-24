#ifndef MOON_H
#define MOON_H
#include <vector>

class Cliente{
  // Tutto nel mese corrente
  unsigned int tempoTelefonate,	// Minuti
    numeroTelefonate,
    numeroSMS,
    trafficoDati;		// MB
  static double datiAlMB;
public:
  double costoDati() const { return trafficoDati*datiAlMB; }
  unsigned int getTempoTelefonate() const { return tempoTelefonate; }
  unsigned int getNumeroSMS() const { return numeroSMS; }
  unsigned int getNumeroTelefonate() const { return numeroTelefonate; }
  virtual double costoMeseCorrente() const = 0; // Costo da pagare nel mese corrente per il cliente
  virtual Cliente* clone() const = 0;
  virtual ~Cliente();
};
double Cliente::datiAlMB = 0.01;

class AlMinuto: public Cliente{
  static double scatto, telefonateAlMinuto, sms;
public:
  double costoMeseCorrente() const {
    return (Cliente::getNumeroTelefonate()*scatto)+(Cliente::getTempoTelefonate()*telefonateAlMinuto)+Cliente::costoDati();
  }
  virtual AlMinuto* clone() const { return new AlMinuto(*this); } 
};
double AlMinuto::scatto = 0.15;
double AlMinuto::telefonateAlMinuto = 0.2;
double AlMinuto::sms = 0.1;

class Abbonamento: public Cliente{
  
  double costoMensile;
  unsigned int sogliaTempo;
  static double oltreSogliaTelefonate;

public:
  virtual Abbonamento* clone() const { return new Abbonamento(*this); }
  bool sogliaSuperata() const {
    return sogliaTempo <= Cliente::getTempoTelefonate();
  }
  double costoMeseCorrente() const {
    return (costoMensile + Cliente::costoDati() + (sogliaSuperata() ? (sogliaTempo-Cliente::getTempoTelefonate())*oltreSogliaTelefonate : 0));
  }
  unsigned int getSoglia() { return sogliaTempo; }
};
double Abbonamento::oltreSogliaTelefonate = 0.3;

class SedeMoon{
  std::vector<Cliente*> clienti;
public:
  ~SedeMoon(){
    for(std::vector<Cliente*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it)
      delete *it;
  }
  SedeMoon(const SedeMoon& s){
    for(std::vector<Cliente*>::const_iterator it = s.clienti.begin(); it != s.clienti.end(); ++it){
      clienti.push_back((*it)->clone());
    }
  }
  SedeMoon& operator=(const SedeMoon& s){
    if(this != &s){
      for(std::vector<Cliente*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it)
	delete *it;
      clienti.clear();
      for(std::vector<Cliente*>::const_iterator it = s.clienti.begin(); it != s.clienti.end(); ++it){
	clienti.push_back((*it)->clone());
      } 
    }
    return *this;
  }
  void aggiungiCliente(const Cliente& c){
    clienti.push_back(c.clone());	// SERVE LA CLONE!!
  }
  double incassoMensileCorrente() const {
    double incasso = 0; 
    for(std::vector<Cliente*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      incasso += (*it)->costoMeseCorrente();
    }
    return incasso;
  }
  int numClientiAbbonatiOltreSoglia() const {
    int count = 0;
    for(std::vector<Cliente*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      const Abbonamento* current = dynamic_cast<const Abbonamento*>(*it);
      if(current && current->sogliaSuperata()){
	++count;
      }
    }
    return count;
  }
  std::vector<AlMinuto> alMinutoSMS(int k) const {
    std::vector<AlMinuto> to_return;
    for(std::vector<Cliente*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      const AlMinuto* current = dynamic_cast<const AlMinuto*>(*it);
      if(current && current->getNumeroSMS() > k)
	to_return.push_back(*current);
    }
    return to_return;
  }
};
#endif
