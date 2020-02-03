#include "iZod.h"

class iZod{
  class Brano{
  public:
    FileAudio* file;
    Brano(FileAudio* ptr = nullptr):file(ptr->clone()){}
    Brano(const Brano& b):file(b.file->clone()){}
    ~Brano(){ delete file; }
    Brano& operator=(const Brano& b){
      if(this != &b){
	delete file;
	if(b.ptr) file = b.ptr->clone();
	else file = nullptr;
      }
      return *this;
    }
  };

  std::vector<Brano> playlist;

  static bool search(FileAudio* file) {
    bool trovato = false;
    for(auto it = playlist.begin(); !trovato && it != playlist.end(); ++it){
      trovato = *(it->file) == *file;
    }
    return trovato;
  }
  
public:

  std::vector<Mp3> mp3(double dim, int bitrate) const {
    std::vector<Mp3> to_return;
    for(auto it = playlist.begin(); it != playlist.end(); ++it){
      const Mp3* tmp = dynamic_cast<const Mp3*>(it->ptr);
      if(tmp && tmp->size() > dim && tmp->getBitrate() > bitrate)
	to_return.push_back(*tmp);
    }
    return to_return;
  }

  std::vector<FileAudio*> braniQual() const {
    std::vector<FileAudio*> to_return;
    for(auto it = playlist.begin(); it != playlist.end(); ++it){
      const WAV* file = dynamic_cast<const WAV*>(it->ptr);
      if((it->ptr)->qualita() && (!file || file->isLossless()))
	to_return.push_back(it->ptr);
    }
    return to_return;
  }

  void insert(Mp3* file){
    if(!search(file))
      playlist.push_back(file);
  }
};
