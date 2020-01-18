#include <iostream>
#include <string>
#include <typeid>

class FileAudio{
  std::string title;
  double size;
public:
  virtual ~FileAudio();
  virtual FileAudio* clone() const = 0;
  virtual bool qualita() const = 0;
  double getSize() const{ return size; }
};

class Mp3: public FileAudio{
  unsigned int bitrate; 	// Kbit/s
  static unsigned int soglia;
public:
  Mp3* clone() const{
    return new Mp3(*this);
  }
  bool qualita() const{
    return bitrate >= soglia;
  }
};
unsigned int Mp3::soglia = 192; // Good practice più che effettivamente necessario

class WAV: public FileAudio{
  unsigned int campionamento; 	// KHz
  bool lossLess;
public:
  WAV* clone() const{
    return new WAV(*this);
  }
  bool qualiata() const{
    return campionamento >= soglia
  }
};
unsigned int WAV::soglia = 96; // Good practice più che effettivamente necessario

class iZod{
  class Brano{
  public:
    FileAudio* ptr;
    Brano(FileAudio* p):ptr(p->clone()){}
    Brano(const Brano& b):ptr((b.ptr)->clone()){}
    ~Brano(){ delete ptr; }
    Brano& operator=(const Brano& b){
      if(this != b){
	delete ptr;
	ptr = (b.ptr)->clone;
      }
      return *this;
    }
  };
  std::vector<Brano> musica;
public:
  std::vector<Mp3> mp3(double dim, int br){
    std::vector<Mp3> da_tornare;
    for (const auto& audio : musica){
      if(typeid(const Mp3&) == typeid(*audio)){
	if(audio.getSize() >= dim && audio.getBitrate() >= br)
	  da_tornare.push_back(*audio);
      }
    }
    return da_tornare;
  }
};
