#include <iostream>

template<class T>class bTree;
template<class T>std::ostream& operator<<(std::ostream&, const bTree<T>&);

template<class T>
class bTree{
  friend std::ostream& operator<< <T>(std::ostream&,const bTree<T>&);

  class nodo{
  public:
    T info;
    nodo *left, *right, *father;
    int state;
    nodo(const T& obj, nodo* f=nullptr, nodo* l=nullptr, nodo* r=nullptr):
      info(obj), father(f), left(l), right(r), state(0) {};
    nodo(const nodo& n, nodo* f=nullptr):
      info(n.info),
      father(f),
      left(n.left ? new nodo(*(n.left),this) : nullptr),
      right(n.right ? new nodo(*(n.right),this) : nullptr),
      state(0){}
    ~nodo() { delete left; delete right; }
  } *_root;


  static nodo* push(const T& obj, nodo* r){
    if(!r) return new nodo(obj);
    if(obj > r->info){
      r->right = push(obj, r->right);
      r->right->father = r;
    }
    else {
      r->left = push(obj, r->left);
      r->left->father = r;
    }
    return r;
  }
  
public:

  bTree():_root(nullptr){}
  bTree(const T& obj):_root(new nodo(obj)){}
  ~bTree(){ delete _root; }
  bTree& operator=(const bTree& right){
    if(this != &right){
      delete _root;
      _root = new nodo(*(right._root));
    }
    return *this;
  }
  void insert(const T& obj){
    _root = push(obj,_root);
  }
  void clear(){
    delete _root;
    _root = nullptr;
  }
  bool empty(){
    return _root == nullptr;
  }

  class prefix_iterator{
    friend class bTree<T>;
    nodo* ptr;
    prefix_iterator(nodo* r=nullptr):ptr(r){ if(ptr) ptr->state = 0; }
  public:
    prefix_iterator& operator++(){
      if(ptr)
	switch(ptr->state){
	case 0:
	  ptr->state = 1;
	  if(ptr->left){
	    ptr = ptr->left;
	    ptr->state = 0;
	  }
	  else ++(*this);
	  break;
	case 1:
	  ptr->state = 2;
	  if(ptr->right){
	    ptr = ptr->right;
	    ptr->state = 0;
	  }
	  else ++(*this);
	  break;
	case 2:
	  while(ptr && ptr->state == 2){
	    ptr->state = 0;
	    ptr = ptr->father;
	  }
	  break;
	}
      return *this;
    }
    const T& operator*() const { return ptr->info; }
    const T* operator->() const { return &(ptr->info); }
    bool operator==(const prefix_iterator& right) const {
      return ptr == right.ptr;
    }
    bool operator!=(const prefix_iterator& right) const {
      return ptr != right.ptr;
    }
  };
  
  prefix_iterator preroot() const {
    return prefix_iterator(_root);
  }

  prefix_iterator preend() const {
    return prefix_iterator();
  }
};

// gli iterator non funzionano, che fare? più problema logico che di linguaggio
template<class T>
std::ostream& operator<<(std::ostream& os, const bTree<T>& bt){
  for(typename bTree<T>::prefix_iterator it = bt.preroot(); it != bt.preend(); ++it){
    os << *it << ' ';
  }
  return os;
}

int main(){
  bTree<int> integers;
  bTree<char> alphabet;

  // for(int i=0; i<10; i++){
  //   integers.insert(i);
  // }
  integers.insert(5);
  integers.insert(6);
  integers.insert(9);
  integers.insert(3);
  integers.insert(7);
  integers.insert(1);
  integers.insert(6);
  integers.insert(0);

  for(char l='A'; l<'z'; l++){
    alphabet.insert(l);
  }

  std::cout << integers << std::endl << alphabet << std::endl;
}
