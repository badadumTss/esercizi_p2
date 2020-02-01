#ifndef MOON_H
#define MOON_H
#include <vector>

/* CLASSE CLIENTE */
class Cliente{
  double minuti, dati;		// tempo: minuti, dati: MB;
  unsigned int n_telefonate, n_sms;
public:
  static double euro_per_dato;
  virtual ~Cliente() = default;
  virtual Cliente* clone() const = 0;
  virtual double costoMeseCorrente() const = 0;
  virtual bool sogliaSuperata() const { return false; }
  double getMinuti() const { return minuti; }
  double getDati() const { return dati; }
  double getSMS() const { return n_sms; }
};
double Cliente::euro_per_dato = 0.01;

/* CLASSE AL_MINUTO */
class AlMinuto: public Cliente{
  static double scatto_alla_risposta, costo_telefonate, costo_SMS;
public:
  AlMinuto* clone() const { return new AlMinuto(*this); }
  double costoMeseCorrente() const {
    return getDati()*euro_per_dato + scatto_alla_risposta + getMinuti()*costo_telefonate + getSMS()*costo_SMS;
  }
};
double AlMinuto::scatto_alla_risposta = 0.15;
double AlMinuto::costo_telefonate = 0.2;
double AlMinuto::costo_SMS = 0.1;

/* CLASSE ABBONAMENTO */
class Abbonamento: public Cliente{
  double costo_abbonamento, minuti_inclusi;
  static double costo_oltre_soglia;
public:
  Abbonamento* clone() const { return new Abbonamento(*this); }
  double costoMeseCorrente() const {
    double tot = costo_abbonamento + getDati()*euro_per_dato;
    if(sogliaSuperata())
      tot += (getMinuti() - minuti_inclusi) * costo_oltre_soglia;
    return tot;
  }
  bool sogliaSuperata() const { return minuti_inclusi < getMinuti(); }
};
double Abbonamento::costo_oltre_soglia = 0.3;

/* CONTENITORE MOON */
class sedeMoon{
  std::vector<Cliente*> clienti;
public:
  void aggiungiCliente(const Cliente& c){
    clienti.push_back(c.clone());
  }
  double incassoMensile() const {
    double incasso = 0;
    for(std::vector<Cliente*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      incasso += (*it)->costoMeseCorrente();
    }
    return incasso;
  }
  int numClientiAbbonatiOltreSoglia() const {
    int count = 0;
    for(std::vector<Cliente*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      count += ((*it)->sogliaSuperata() ? 1 : 0);
    }
    return count;
  }
  std::vector<AlMinuto> alMinutoSMS(int k) const {
    std::vector<AlMinuto> to_return;
    for(std::vector<Cliente*>::const_iterator it = clienti.begin(); it != clienti.end(); ++it){
      AlMinuto* ptr = dynamic_cast<AlMinuto*>(*it);
      if(ptr && ptr->getSMS() > k)
	to_return.push_back(*ptr);
    }
    return to_return;
 } 
};

#endif
