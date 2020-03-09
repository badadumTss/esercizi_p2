#include <iostream>
#include <vector>
#include <list>

class App{
  double size;
  bool needs_internet;
public:
  App(double dim = 0, bool internet = true):size(dim),needs_internet(internet){}
  double getSize() const { return size; }
  virtual App* clone() const = 0;
};

class FreeApp: public App{
  bool foss;
public:
  FreeApp(double dim = 0, bool internet = true, bool open = false):App(dim,internet),foss(open){}
  FreeApp* clone() const { return new FreeApp(*this); }
  bool isFoss() const { return foss; }
};

class PayApp: public App{
  double price;
public:
  PayApp(double prezzo, double dim = 0, bool internet = true):App(dim,internet),price(prezzo > 0 ? prezzo : 0.0/*dovrebbe in realtà sollevare un'eccezione*/){}
  PayApp* clone() const { return new PayApp(*this); }
  double getPrice() const { return price; }
};

class aiPhone{
  std::list<App*> app_installate;
  double mem_residua;

public:

  ~aiPhone(){ for(auto it = app_installate.begin(); it != app_installate.end(); ++it) delete *it; }
  aiPhone(const aiPhone& phone){
    for(auto it = phone.app_installate.begin(); it != phone.app_installate.end(); ++it)
      app_installate.push_back((*it)->clone());
  }
  aiPhone& operator=(const aiPhone& phone){
    if(this != &phone){
      for(auto it = app_installate.begin(); it != app_installate.end(); ++it) delete *it;
      app_installate.clear();
      for(auto it = phone.app_installate.begin(); it != phone.app_installate.end(); ++it)
	 app_installate.push_back((*it)->clone());
    }
    return *this;
  }
  
  double installaApp(const App& app){ // non costante perchè inserisco zi
    if(app.getSize() < mem_residua){
      app_installate.push_back(app.clone());
      return mem_residua - app.getSize();
    }
  }

  std::vector<PayApp> F(double x){
    std::vector<PayApp> to_return;
    for(auto it = app_installate.begin(); it != app_installate.end(); ++it){
      PayApp* ptr = dynamic_cast<PayApp*>(*it);
      if(ptr && (ptr->getPrice()) <= x)
	to_return.push_back(*ptr);
    }
    return to_return;
  }

  FreeApp* G() const {
    double max_mem = 0;
    for(auto it = app_installate.begin(); it != app_installate.end(); ++it){
      if((*it)->getSize() > max_mem) max_mem = (*it)->getSize();
    }

    FreeApp* to_return = nullptr;
    for(auto it = app_installate.begin(); !to_return && it != app_installate.end(); ++it){
      FreeApp* current = dynamic_cast<FreeApp*>(*it);
      if(current && current->isFoss() && current->getSize() == max_mem) to_return = current;
    }
    return to_return; // in realtà andrebbe sollevata un'eccezione se to_return == nullptr ma non le abbiamo fatte
  }
};

/*
  compila, non so se ho mem leak o altro
*/
