#ifndef TRIALBERO_H
#define TRIALBERO_H

template<class T> class trialbero;

template<class T>
std::ostream& operator<<(std::ostream&, const trialbero<T>&);

template<class T>
class trialbero{

  friend std::ostream& operator<< <T>(std::ostream&, const trialbero<T>&);

  class nodo{
  public:
    T info;
    nodo *left, *right, *middle;
    nodo(const T& obj, nodo* l=nullptr, nodo* m=nullptr, nodo* r=nullptr):
      info(obj), left(l), middle(m), right(r) {}
    ~nodo(){ delete left; delete right; delete middle; }
  } *root;

  static nodo* copy(nodo* root){
      if(!root) return nullptr;
      return new nodo(root->info,copy(root->left), copy(r->middle), copy(r->right));
    }

  static std::ostream& print(std::ostream& os, nodo* root){
    if(root){
      os << root->info ;
      os << '(';
      print(os,root->left);
      os << ',';
      print(os,root->middle);
      os << ',';
      print(os,root->right);
      os << ')';
    } else os << '_';
    return os;
  }

public:
  
  trialbero():root(nullptr){}
  trialbero(const T& obj):root(new nodo(obj)){}
  trialbero(const trialbero& tree):root(copy(tree.root)){}
  ~trialbero(){ delete root; }
  trialbero& operator=(const trialbero& tree){
    if(this != &tree){
      delete root;
      root = copy(tree.root);
    }
    return *this;
  }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const trialbero<T>& tree){
  return print(os,tree.root);
}

#endif
