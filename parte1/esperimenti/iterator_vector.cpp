#include<iostream>
#include<vector>
#include<string>

int main(int argc, char *argv[]){
  std::vector<char*> stringhe;
  for( int i=0; i<argc; i++ ){
    stringhe.push_back(argv[i]);
  }
  std::vector<char*>::iterator it = stringhe.begin();
  while( it != stringhe.end() ){
    std::cout << *it << std::endl;
    ++it;
  }

  return 0;
}
