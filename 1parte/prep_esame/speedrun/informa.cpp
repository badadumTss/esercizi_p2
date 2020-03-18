#include <iostream>
#include <vector>

class Workout{
protected:
  unsigned int minuti_allenamento;
public:
  virtual ~Workout(){};
  virtual Workout* clone() const = 0;         // clona l'oggetto puntato
  virtual int calorie() const = 0;	      // calorie che l'allenamento ti fa sudare
};

class Corsa: public Workout{
  double km_percorsi;
public:
  Corsa* clone() const { return new Corsa(*this); }
  int calorie() const {
    return (500*km_percorsi*km_percorsi)/minuti_allenamento;
  }
};

class Nuoto: public Workout{
protected:
  unsigned int vasche;
public:
  ~Nuoto() = 0;
  virtual Nuoto* clone() const = 0;
  unsigned int getVasche() const { return vasche; }
};

class StileLibero: public Nuoto{
public:
  StileLibero* clone() const { return new StileLibero(*this); }
  int calorie() const {
    return (minuti_allenamento < 10 ? vasche * 35 : vasche * 40);
  }
};

class Dorso: public Nuoto{
public:
  Dorso* clone() const { return new Dorso(*this); }
  int calorie() const {
    return (minuti_allenamento < 15 ? vasche * 30 : vasche * 35);
  }
};

class Rana: public Nuoto{
public:
  Rana* clone() const { return new Rana(*this); }
  int calorie() const {
    return (vasche * 25);
  }
};

class InForma{
  // Contenitore di Workout
  std::vector<const Workout*> allenamenti; // Suppongo di dover accedere casualmente agli allenamenti fatti, e non solamente in testa o in coda
public:
  std::vector<Nuoto*> vasche(int x) const {
    std::vector<Nuoto*> to_return;
    // tutti e sogli gli allenamenti di tipo nuoto con vasche > x
    for(std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it != allenamenti.end(); ++it){
      const Nuoto* tmp = dynamic_cast<const Nuoto*>(*it);
      if(tmp && tmp->getVasche() > x)
	to_return.push_back(tmp->clone());
    }
    return to_return;
  }

  std::vector<Workout*> calorie(int x) const {
    std::vector<Workout*> to_return;
    // tutti e sogli gli allenamenti di tipo nuoto con vasche > x
    for(std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it != allenamenti.end(); ++it){
      if((*it)->calorie() > x && !dynamic_cast<const Rana*>(*it))
	to_return.push_back((*it)->clone());
    }
    return to_return;
  }

  void removeNuoto(){
    /* Rimuove tutti gli allenamenti a nuoto col maggior consumo di calorie tra tutti gli allnamenti a nuoto */
    int max_cal = 0;
    for(std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it != allenamenti.end(); ++it){
      if(dynamic_cast<const Nuoto*>(*it) && (*it)->calorie() > max_cal)
	max_cal = (*it)->calorie();
    }

    bool to_delete;
    for(std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it != allenamenti.end(); (to_delete ? it = allenamenti.erase(it) : ++it)){
      to_delete = (dynamic_cast<const Nuoto*>(*it) && (*it)->calorie() == max_cal);
      if (to_delete) delete *it;
    }
  }
};
