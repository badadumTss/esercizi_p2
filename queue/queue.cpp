#include "./queue.h"
#include <iostream>
#include <string>

class canzoniere{
    std::string _nome;
    int anni_di_servizio;
public:
    canzoniere(const std::string&, int = 0);
    int anniInServizio() const;
    std::string nome() const;
    std::string affidabilita() const;
};

canzoniere::canzoniere(const std::string& n, int a):_nome(n),anni_di_servizio(a){}

int canzoniere::anniInServizio() const{
    return anni_di_servizio;
}

std::string canzoniere::nome() const{
    return _nome;
}

std::string canzoniere::affidabilita() const {
    if(anni_di_servizio <= 1) return "Molto bassa";
    if(anni_di_servizio <= 5) return "Bassa";
    if(anni_di_servizio <= 10) return "Media";
    return "Alta";
}

std::ostream& operator<<(std::ostream& os, const canzoniere& c){
    return os << c.nome() << ": " << c.anniInServizio() << " anni di servizio, affidabilità " << c.affidabilita();
}

int main(){
    Queue<canzoniere> Gruppo;
    Gruppo.add(canzoniere("Giovanni", 3)).add(canzoniere("Marco", 10)).add(canzoniere("Paolo", 15)).add(canzoniere("Gianpaolo", 25));
    
    std::cout << Gruppo << std::endl;
    return 0;
}
