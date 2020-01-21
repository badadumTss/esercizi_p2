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
  std::vector<const Workout *> allenamenti;
public:
  std::vector<Nuoto*> vasche(int x) const{
    std::vector<Nuoto*> to_return;
    for (auto it = allenamenti.begin(); it != allenamenti.end(); ++it ){
      if ( (*it)->calorie() > x && dynamic_cast<const Nuoto*>(*it) )
	to_return.push_back((dynamic_cast<const Nuoto*>(*it))->clone());
    }
    return to_return;    
  }
  std::vector<Workout*> calorie(int x) const{
    std::vector<Workout*> to_return;
    for (auto it = allenamenti.begin(); it != allenamenti.end(); ++it ){
      if ( (*it)->calorie() > x && dynamic_cast<const Rana*>(*it) ) 
	to_return.push_back((dynamic_cast<const Rana*>(*it))->clone());
    }
    return to_return;    
  }
  void removeNuoto(){
    /* 
    rimuove dagli allenamenti archiviati in app tutti gli allenamenti a nuoto che abbiano il massimo 
    numero di calorie tra tutti gli allenamenti a nuoto 
    */
    // come?? potrei ricostruire la lista ben formata, ma idk
    // itero due volte sul vettore? ci sta
    int max_cal = 0;
    for(auto it = allenamenti.begin(); it != allenamenti.end(); ++it){
      if(dynamic_cast<const Nuoto*>(*it) && (*it)->calorie() > max_cal)
	max_cal = (*it)->calorie();
    }

    //dovrebbe, probabilmente farà errore per il tipo del contenitore
    for(auto it = allenamenti.begin(); it != allenamenti.end(); ++it){
      if(dynamic_cast<const Nuoto*>(*it) && (*it)->calorie() == max_cal)
	allenamenti.erase(it);
    }
    
  }
};
#endif
