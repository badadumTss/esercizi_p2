#include <iostream>
#include <vector>
#include <list>
#include <string>

class Nome{
  std::string value;
public:
  std::string get() const { return value; }
  bool operator==(const Nome& n) const {
    return value == n.value;
  }
};

class Numero{
  std::string value;
public:
  std::string get() const { return value; }
  bool operator==(const Numero& n) const {
    return value == n.value;
  }
};

class Contatto{
  Nome _nome_;
public:
  virtual Contatto* clone() const = 0;
  virtual bool operator==(const Contatto& c) const = 0;
  virtual bool videochat() const = 0; // true sse il contatto è disponibile a videochiamate
  Nome getNome() const { return _nome_; }
};

class Telefonico: public Contatto{
  Numero _numero_;
  bool whatsapp;
  unsigned int n_sms;
public:
  Telefonico* clone() const { return new Telefonico(*this); }
  bool operator==(const Contatto& c) const {
    const Telefonico* tmp = dynamic_cast<const Telefonico*>(&c);
    return (tmp && _numero_ == tmp->_numero_ );
  }
  unsigned int getSMS() const { return n_sms; }
  bool videochat() const { return whatsapp; }
};

class Skype: public Contatto{
  Nome nickname;
  bool video;
public:
  Skype* clone() const { return new Skype(*this); }
  bool operator==(const Contatto& c) const {
    const Skype* tmp = dynamic_cast<const Skype*>(&c);
    return (tmp && nickname == tmp->nickname );
  }
  bool videochat() const { return video; }
};

class Rubrica{
  class Entry{
  public:
    Contatto* contact;
    unsigned int count;
    // giusto che non controlli c, tocca a insert, altrimenti posso creare entry vuote e non ha senso
    Entry(Contatto* c, int s = 1):contact(c->clone()),count(s>0 ? s : 0){}
    Entry(const Entry& e):contact(e.contact->clone()),count(e.count){}
    ~Entry(){ delete contact; }
    Entry& operator=(const Entry& e){
      if(this != &e){
	delete contact;
	contact = e.contact->clone();
	count = e.count;
      }
      return *this;
    }
  };

  std::vector<Entry> contatti;
public:

  void insert(Contatto* c, int s){
    bool found = false;
    for(auto it = contatti.begin(); !found && it != contatti.end(); ++it){
      if(*(it->contact) == *c){
	++(it->count);
	found = true;
      }
    }
    if(!found) contatti.push_back(c);
  }

  std::list<Telefonico> tel(const Nome& n, int s) const {
    std::list<Telefonico> to_return;
    for(auto it = contatti.cbegin(); it != contatti.cend(); ++it){
      const Telefonico* ptr = dynamic_cast<const Telefonico*>(it->contact);
      if(ptr && ptr->getSMS() >= s && n == ptr->getNome()) to_return.push_back(*ptr);
    }
    return to_return;
  }

  int whatsCall() const {
    int count = 0;
    for(auto it : contatti) if(it.contact->videochat()) ++count;
    return count;
  }
};
