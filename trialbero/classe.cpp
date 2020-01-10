/* 
Definire un template di classe albero<T> i cui oggetti rappresentano 
un albero 3-ario ove i nodi memorizzano dei valori di tipo T ed hanno 
3 figli (invece dei 2 figli di un usuale albero binario). Il template 
albero<T> deve soddisfare i seguenti vincoli:
1. Deve essere disponibile un costruttore di default che costruisce l’albero vuoto. 
2. Gestione della memoria senza condivisione.
3. Metodo void insert(const T&): a.insert(t) inserisce nell'albero a una nuova radice che memorizza il valore t ed avente come figli 3 copie di a 
4. Metodo bool search(const T&): a.search(t) ritorna true se t occorre nell'albero a, altrimenti ritorna false.
5. Overloading dell'operatore di uguaglianza.
6. Overloading dell'operatore di output.

*/

#include<iostream>

template<class T>
class trialbero;

template <class u> 
std::ostream& operator<<(std::ostream&, const trialbero<u>&);

template <class T> 
class trialbero {

friend std::ostream& operator<< <T>(std::ostream&, const trialbero <T> &);

private:
  class nodo {
  public:
    nodo(const T& t = T(), nodo* s=0, nodo* c=0, nodo* d=0):
      info(t), sx(s), cx(c), dx(d) {}
    T info;
    nodo *sx, *cx, *dx;
    
  };
  nodo* root; // trialbero vuoto iff root==nullptr
  static nodo* copy(nodo* p) {
    if(!p) return nullptr;
    // p!= nullptr
    return new nodo(p->info,copy(p->sx), copy(p->cx), copy(p->dx)); 
  }

  static std::ostream& rec_print(std::ostream& os, nodo* r) {
    if(r){
      os << r->info << "(";
      rec_print(os,r->sx) << ",";
      rec_print(os,r->cx) << ",";
      rec_print(os,r->dx) << ")";
    } else os << "_";
    return os;
  }
  static void destroy(nodo* p) {
    if(p!=nullptr) {
      destroy(p->sx);
      destroy(p->cx);
      destroy(p->dx);
      delete p; 
    } 
  }
  static bool rec_search(nodo* p, const T& t) {
    if(!p) return false;
    // p!=nullptr
    return p->info==t || rec_search(p->sx,t) ||
      rec_search(p->cx,t) ||rec_search(p->dx,t);
  }
  static bool rec_equality(nodo* p1, nodo* p2) {
    if(!p1 && !p2) return true;
    // p1 || p2
    if(!p1 || !p2) return false;
    // p1 && p2
    return p1->info==p2->info && rec_equality(p1->sx,p2->sx) &&
      rec_equality(p1->cx,p2->cx) && rec_equality(p1->dx,p2->dx);
  } 
  
public:
  trialbero(): root(nullptr) {}
  trialbero(const trialbero& t): root(copy(t.root)) {}
  trialbero& operator=(const trialbero& t) {
    if(this != &t) {
      destroy(root);
      root=copy(t.root);
    }
    return *this;
  }
  ~trialbero() {destroy(root);} 
  void insert(const T& t) {
    root = new nodo(t,root,copy(root),copy(root));
  }
  // T deve offrire operator==
  bool search(const T& t) const {
    return rec_search(root,t);
  }
  bool operator==(const trialbero& t) const {
    return rec_equality(root,t.root);
  }
};

template <class T> 
std::ostream& operator<< (std::ostream& os, const trialbero<T>& t) {
  return trialbero<T>::rec_print(os,t.root);
}

int main() {
  trialbero<int> t1, t2, t3;
  t1.insert('b');
  t1.insert('a');
  t2.insert('a');
  t3 = t1;
  t3.insert('c');
  std::cout << (t1 == t2) << std::endl; 
  std::cout << t1.search('b') << std::endl; 
  std::cout << t1 << std::endl << t2 << std::endl << t3 << std::endl;
}

