#ifndef ANOMALIA_H
#define ANOMALIA_H
#include <string>
#include <iostream>

class Anomalia{
  //dovrebbe gestire le eccezioni, non avendole ancora fatte non le implemento
  char desc;
public:
  Anomalia(const char& c):
    desc(c == 's' ? 's' :
	 c == 'v' ? 'v' :
	 c == 'd' ? 'd' : 'c')
    {}
  std::string getAnomalia() const {
    std::string to_return;
    switch(desc){
    case 's':
      to_return = "Anomalia SMS";
      break;
    case 'v':
      to_return = "Anomalia Voce";
      break;
    case 'd':
      to_return = "Anomalia Dati";
      break;
    case 'c':
      to_return = "Anomalia Addebito costo";
      break;
    }
    return to_return;
  }
};

std::ostream& operator<<(std::ostream& os, const Anomalia& a){
	return os << a.getAnomalia();
}

#endif
