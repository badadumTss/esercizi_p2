#include "coda.h"

int main(){
    coda<char> c(10,'a');
    c.insert('b');
    std::cout << "coda: " << c << std::endl;
    return 0;
}
