#include <iostream>
#include <list>

class File{
  double __dimensione__;
  bool __accessibile__;
public:
  File(double dimensione = 0, bool accessibile = true):__dimensione__(dimensione),__accessibile__(accessibile){}
  virtual ~File() = 0;
  bool accessibile() const { return __accessibile__; }
  double getDimensioni() const { return __dimensione__; }
};

class Audio: public File{
  bool __lossy__;
public:
  Audio(double Dimensioni = 0, bool Accessibile = true, bool lossy = false):File(Dimensioni,Accessibile),__lossy__(lossy){}
  bool isLossy() const { return __lossy__; }
};

class Mp3: public Audio{
public:
  Mp3(double Dimensioni = 0, bool Accessibile = true):Audio(Dimensioni,Accessibile,true){}
};

class Video: public File{
  unsigned int __framerate__;	// freq in Hz
public:
  Video(double Dimensioni = 0, bool Accessibile = true, unsigned int framerate = 24):File(Dimensioni,Accessibile),__framerate__(framerate){}
  unsigned int frames() const { return __framerate__; }
};


class QooqleDrive{
  std::list<const File*> files;
  double max_size, current_size;
public:
  
  Audio uploadFile(File& current){
    Audio* ptr = dynamic_cast<Audio*>(&current);
    if(ptr && ptr->accessibile() && ptr->getDimensioni() < (max_size - current_size)){
      files.push_back(ptr);
    } // else { throw (Exc e); }
    return *ptr;
  }

  std::list<Audio*> audioCopy() const {
    std::list<Audio*> to_return;
    for(std::list<const File*>::const_iterator it = files.begin(); it != files.end(); ++it){
      const Audio* ptr = dynamic_cast<const Audio*>(*it);
      if(ptr && (!(ptr->isLossy()) || dynamic_cast<const Mp3*>(ptr)))
	to_return.push_back(const_cast<Audio*>(ptr));
    }
    return to_return;
  }

  Video* minVideo(unsigned int fr) const {
    Video* min = nullptr;
    for(auto it = files.begin(); it != files.end(); ++it){
      const Video* current = dynamic_cast<const Video*>(*it);
      if(current && current->frames() > fr && (!min || current->getDimensioni() < min->getDimensioni()))
	min = current;
    }
    return const_cast<Video*>(min); // in realtà andrebbe fatto un if(current) e nell'else sollevare l'eccezione, che però non abbiamo fatto per ora
  }
};
