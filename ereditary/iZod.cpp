#include <iostream>
#include <string>

class FileAudio{
  std::string title;
  unsigned int size;
public:
  virtual ~FileAudio();
  virtual FileAudio* clone() const = 0;
  virtual bool qualita() const = 0;
}
