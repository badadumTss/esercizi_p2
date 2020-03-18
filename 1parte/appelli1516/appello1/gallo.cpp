#include <iostream>
#include <vector>

class GalloFile{
  double _size;
public:
  virtual ~GalloFile() = default;	// distruttore virtuale, necessario per ogni istanziazione polimorfa di gerarchie di classi
  virtual GalloFile* clone() const = 0; // clonazione standard
  virtual bool highQuality() const = 0;		// true sse il file è considerato ad alta qualità
  double getSize() const { return _size; }
};

class Foto: public GalloFile{
  unsigned int ISO;
  bool _flash;
public:
  Foto* clone() const { return new Foto(*this); }
  bool highQuality() const { return (ISO >= 500); }
  bool flash() const { return _flash; }
};

class Video: public GalloFile{
  unsigned int secondi;
  bool fullHD;
public:
  Video* clone() const { return new Video(*this); }
  bool highQuality() const { return fullHD; }
  unsigned int durata() const { return secondi; }
};

class Gallo{
  std::vector<GalloFile*> files;
public:
  std::vector<GalloFile*> selectHQ() const {
    std::vector<GalloFile*> to_return;
    for(std::vector<GalloFile*>::const_iterator it = files.begin(); it != files.end(); ++it){
      Foto* tmp = dynamic_cast<Foto*>(*it);
      if((*it)->highQuality() && (!tmp || tmp->flash()))
	to_return.push_back((*it)->clone());
    }
    return to_return;
  }

  void removeNonFoto(double size){
    bool to_delete;
    int initial_size = files.size(); 
    for(std::vector<GalloFile*>::iterator it = files.begin(); it != files.end(); to_delete ? it = files.erase(it) : ++it){
      to_delete = false;
      Foto* current = dynamic_cast<Foto*>(*it);
      if(!current && (*it)->getSize() > size){
	delete *it;
	to_delete = true;
      }
    }
    // if(files.size() == initial_size) std::logic_error("NoRemove");
  }

  const GalloFile* insert(const GalloFile* pf){
    const Video* current = dynamic_cast<const Video*>(pf);
    if(!current || current->durata() < 60){
      files.push_back(pf->clone());
      return files.back();
    } return nullptr;
  }
};
