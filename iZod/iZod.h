#ifndef FILEAUDIO_H
#define FILEAUDIO_H

#include <iostream>
#include <string>

class FileAudio{
  std::string titolo;
  double _size;
public:
  FileAudio* clone() const = 0;
  bool qualita() const = 0;
  double size() const { return _size; }

  virtual bool operator==(FileAudio& file) const {
    return titolo == file.titolo;
  }
};

class Mp3: public FileAudio{
  unsigned int bitrate;
  static unsigned int soglia_qualita;
public:
  Mp3* clone() const { return new Mp3(*this); }
  bool qualita() const { return bitrate > soglia_qualita; }
  unsigned int getBitrate() const { return bitrate; }
  bool operator==(const FileAudio& file) const {
    if(typeid(file) == typeid(const Mp3&)){
      const Mp3* tmp = dynamic_cast<const Mp3*>(&file);
      return FileAudio::operator==(file) && tmp->bitrate == bitrate;
    } else return false;
  }
};
unsigned int Mp3::soglia_qualita = 192;

class WAV: public FileAudio{
  unsigned int sampling;
  bool lossless;
  static unsigned int soglia_qualita;
public:
  WAV* clone() const { return new WAV(*this); }
  bool qualita() const { return sampling > soglia_qualita; }
  bool isLossless() const { return lossless; }
  bool operator==(const FileAudio& file) const {
    if(typeid(file) == typeid(const WAV&)){
      const WAV* tmp = dynamic_cast<const WAV*>(&file);
      return FileAudio::operator==(file) && tmp->sampling == sampling && tmp->lissless == lossless;
    } else return false;
  }
};
unsigned int WAV::soglia_qualita = 96;

#endif
