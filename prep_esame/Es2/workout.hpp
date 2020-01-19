#ifndef WORKOUT_H
#define WORKOUT_H

class Workout{
  unsigned int minuti;
public:
  Workout* clone() = 0;
  int calorie() = 0;
  unsigned int getMinuti(){ return minuti; }
  virtual ~Workout();
};

class Corsa: public Workout{
  unsigned int Distanza;
public:
  Corsa* clone(){
    return new Corsa(*this);
  }
  int calorie(){
    int min = getMinuti();
    if(min){
      return (500 * Distanza * Distanza)/min;
    } else return 0;
  }
};

class Nuoto: public Workout{
  unsigned int vasche;
public:
  virtual ~Nuoto() = 0;
  unsigned int getVasche(){ return vasche; }
};

class StileLibero: public Nuoto{
public:
  StileLibero* clone(){ return new StileLibero(*this); }
  int calorie(){
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
  Dorso* clone(){ return new Dorso(*this); }
  int calorie(){
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
  Rana* clone(){ return new Rana(*this); }
  int calorie(){
    int min = getMinuti();
    if(min){
      return 25 * getVasche();
    } else return 0;
  }
};

class InForma{
  std::vector<const Workout *> allenamenti;
public:
  std::vector<Nuoto*> vasche(int a){
    // copie di tutti e soli gli allenamenti a nuoto memorizzati in app con un numero di vasche percorse > v
  }
  std::vector<Workout*> calorie(int a){
    /* 
    copie di tutti e soli gli allenamenti memorizzati in app che : (i) hanno comportato un consumo di
    calorie > x ; e (ii) non sono allenamenti di nuoto a rana.
    */
  }
  void removeNuoto(){
    /* 
    rimuove dagli allenamenti archiviati in app tutti gli allenamenti a nuoto che abbiano il massimo 
    numero di calorie tra tutti gli allenamenti a nuoto 
    */
  }
};
#endif
