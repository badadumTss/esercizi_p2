#include<iostream>
#include<vector>

enum Laurea {Informatica, Ingegneria, Altro};

class ICTstaff{
  double stipendio;
  Laurea titolo;
  bool magistrale;
protected:
  double getStipendio() const { return stipendio; }
public:
  virtual ~ICTstaff() = default;
  virtual ICTstaff* clone() const = 0;
  virtual double salary() const = 0;
  Laurea getTitolo() const { return titolo; }
  bool getMaster() const { return magistrale; }
};

class SwEngineer: public ICTstaff{
  bool security;
  static double extra;
public:
  SwEngineer* clone() const { return new SwEngineer(*this); }
  double salary() const { return getStipendio() + (security ? extra : 0); }
  bool infoSec() const { return security; }
};
double SwEngineer::extra = 500;

class HwEngineer: public ICTstaff{
  unsigned int n_trasferte;
  static double extra;
public:
  HwEngineer* clone() const { return new HwEngineer(*this); }
  double salary() const { return getStipendio() + n_trasferte*extra; }
};
double HwEngineer::extra = 300;

class Amazonia{
  class SmartP{
  public:
    ICTstaff* ptr;
    SmartP(ICTstaff* ict = nullptr):ptr(if(ict) ict->clone()){}
    SmartP(const SmartP& sp):ptr(sp.ptr->clone()){}
    ~SmartP(){ delete ptr; }
    SmartP& operator=(const SmartP& sp){
      if(this != &sp){
	delete ptr;
	if(sp.ptr) ptr = sp.ptr->clone();
	else ptr = nullptr;
      }
    }
    ICTstaff& operator*() const { return *ptr; }
    ICTstaff* operator->() const { return ptr; }
  };

  std::list<SmartP> dipendenti;

public:
  bool insert(SwEngineer* dip, unsigned int k){
    bool to_return;
    int count = 0;
    for(std::vector<SmartP>::const_iterator it = dipendenti.begin(); it != dipendenti.end(); ++it){
      SwEngineer* current = dynamic_cast<SwEngineer*>(it->ptr);
      if(current && current->infoSec()) ++count;
    }
    to_return = count < k;
    if(to_return) dipendenti.push_back(dip);
    return to_return;
  }

  std::vector<HwEngineer> fire(double stip){
    std::vector<HwEngineer> to_return;
    bool to_del;
    for(std::vector<SmartP>::const_iterator it = dipendenti.begin(); it != dipendenti.end(); to_del ? it = dipendenti.erase(it) : ++it){
      to_del = (*it)->salary() > stip;
      if(to_del){
	HwEngineer* current = dynamic_cast<HwEngineer*>(it->ptr);
	if(current) to_return.push_back(*current);
      }
    }
    return to_return;
  }

  std::vector<SwEngineer*> masterInf() const {
    std::vector<SwEngineer*> to_return;
    for(auto it = dipendenti.cbegin(); it != dipendenti.cend(); ++it){
      const SwEngineer* current = dynamic_cast<const SwEngineer*>(it->ptr);
      if(current && current->getTitolo() == Informatica && current->getMaster())
	to_return.push_back(current);
    }
  }
};
