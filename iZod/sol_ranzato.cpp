// Esercizio 11.18 del libro

#include<string>
#include<vector>
#include<typeinfo>
using namespace std;

class FileAudio { // base astratta e polimorfa
private:
  std::string titolo;
  double size;
public:
  virtual bool qualita() const =0;
  // costruttore di copia polimorfa
  virtual FileAudio* clone() const =0;
  virtual ~FileAudio() {}
  double getSize() const {return size;}
  virtual bool operator==(const FileAudio& f) const {
    return titolo==f.titolo && size == f.size;
  } 
};

class Mp3: public FileAudio {
private:
  unsigned int bitrate; // Kbit/s
  static unsigned int sogliaDiQualita;
public:
  unsigned int getBitRate() const {return bitrate;}
  virtual bool qualita() const {return bitrate >= sogliaDiQualita;}
  virtual Mp3* clone() const { return new Mp3(*this);}
  virtual bool operator==(const FileAudio& f) const {
    if(typeid(const Mp3&) != typeid(f)) return false;
    const Mp3* p = static_cast<const Mp3*>(&f);
    return FileAudio::operator==(f) && bitrate == p->bitrate;
  }
};
unsigned int Mp3::sogliaDiQualita = 256;

class WAV: public FileAudio {
private:
  unsigned int frequenza; // KHz
  bool lossLess; // true se lossLess
public:
  bool getLossLess() const {return lossLess;}
  virtual bool qualita() const {return frequenza >= 96;}
  virtual WAV* clone() const { return new WAV(*this);}
  virtual bool operator==(const FileAudio& f) const {
    if(typeid(const WAV&) != typeid(f)) return false;
    const WAV* p = static_cast<const WAV*>(&f);
    return FileAudio::operator==(f) && frequenza == p->frequenza && lossLess == p->lossLess;
  }
};

class iZod {
private:
  // classe annidata di puntarori smart
  class Brano {
  public:
    FileAudio* ptr; // puntatore (super)polimorfo
    Brano(FileAudio* p): ptr(p->clone()) {} // convertitore FileAudio* => Brano
    Brano(const Brano& b): ptr(b.ptr->clone()) {}
    Brano& operator=(const Brano& b) {
      if(this != &b) {
	delete ptr; 
	ptr = b.ptr->clone();
      }
      return *this;
    }
    ~Brano() {delete ptr;}
  };
  
  std::vector<Brano> brani;
public:
  std::vector<Mp3> mp3(double dim, int br) const {
    Mp3* p =nullptr;
    std::vector<Mp3> v;
    for(vector<Brano>::const_iterator cit = brani.begin(); cit!=brani.end(); ++cit) {
      p=dynamic_cast<Mp3*>(cit->ptr); 
      if(p != nullptr && p->getSize()>dim && p->getBitRate() > br)
	v.push_back(*p);
    }
    return v;
  }
  
  std::vector<FileAudio*> braniQual() const {
    WAV* p =nullptr;
    std::vector<FileAudio*> v;
    for(auto cit = brani.begin(); cit!=brani.end(); ++cit) {
      p=dynamic_cast<WAV*>(cit->ptr);
      if((cit->ptr)->qualita() && (!p || p->getLossLess())) 
	v.push_back(cit->ptr); 
    }
    return v;
  }
  
  void insert(Mp3* m) {
    for(vector<Brano>::iterator it = brani.begin(); it!=brani.end(); ++it) 
      if(*m == *(it->ptr)) return;
    brani.push_back(m);
  }
};

int main() {}
