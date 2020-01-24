#ifndef WORKOUT_H
#define WORKOUT_H
#include <vector>

class Workout{
  unsigned int minuti;
public:
  virtual Workout* clone() const = 0;
  virtual int calorie() const = 0;
  unsigned int getMinuti() const{ return minuti; }
  virtual ~Workout();
};

class Corsa: public Workout{
  unsigned int Distanza;
public:
  Corsa* clone() const{
    return new Corsa(*this);
  }
  int calorie() const{
    int min = getMinuti();
    if(min){
      return (500 * Distanza * Distanza)/min;
    } else return 0;
  }
};

class Nuoto: public Workout{
  unsigned int vasche;
public:
  unsigned int getVasche() const{ return vasche; }
  virtual Nuoto* clone() const = 0;
};

class StileLibero: public Nuoto{
public:
  StileLibero* clone() const{ return new StileLibero(*this); }
  int calorie() const{
    int min = getMinuti();
    if(min){
      if(min < 10)
	return 35 * getVasche();
      else return 40 * getVasche();
    } else return 0;
  }
};

class Dorso: public Nuoto{
public:
  Dorso* clone() const{ return new Dorso(*this); }
  int calorie() const{
    int min = getMinuti();
    if(min){
      if(min < 15)
	return 30 * getVasche();
      else return 35 * getVasche();
    } else return 0;
  }
};

class Rana: public Nuoto{
public:
  Rana* clone() const{ return new Rana(*this); }
  int calorie() const{
    int min = getMinuti();
    if(min){
      return 25 * getVasche();
    } else return 0;
  }
};

class InForma{

  std::vector<const Workout*> allenamenti;

public:

  std::vector<Nuoto*> vasche(int x) const{
    std::vector<Nuoto*> to_return;
    for (std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it != allenamenti.end(); ++it){
      const Nuoto* current = dynamic_cast<const Nuoto*>(*it);
      if (current && current->getVasche() > x)
	to_return.push_back(current->clone());
    }
    return to_return;    
  }
  
  std::vector<Workout*> calorie(int x) const{
    std::vector<Workout*> to_return;
    for (std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it != allenamenti.end(); ++it){
      const Rana* current = dynamic_cast<const Rana*>(*it); 
      if (current && current->calorie() > x) 
	to_return.push_back(current->clone());
    }
    return to_return;    
  }
  
  void removeNuoto(){
    int max_cal = 0;
    
    for(auto it = allenamenti.cbegin(); it != allenamenti.cend(); ++it){ // cbegin() ritorna const_iterator!! non iterator!!
      const Nuoto* current = dynamic_cast<const Nuoto*>(*it);
      if(current && current->calorie() > max_cal)
	max_cal = current->calorie();
    }

    // QUI NON TUTTO PERDE ATTIRBUTO CONST: devo eliminare elementi => posso avere iteratori costanti 
    for(std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it != allenamenti.end(); ++it){
      if(dynamic_cast<const Nuoto*>(*it) && (*it)->calorie() == max_cal){
	delete *it;	        // Questo perchè se eliminassi solo la entry del vettore farebbe garbage
	allenamenti.erase(it);	// DETERMINA IL NON CONST IN removeNuoto()
      }
      /*
	Attenzione!! questa cosa qui sopra si può fare solo da c++11, prima no perchè l'eliminazione era considerata
        una 'modifica' dell'oggetto puntato dall'iteratore; dopo c++11 non più (anche gli oggetti costanti in fondo
	cessano di esistere prima o poi)
      */
    }

  }
};
#endif
