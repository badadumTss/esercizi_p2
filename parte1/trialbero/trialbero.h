#ifndef TRIALBERO_H
#define TRIALBERO_H
#include <iostream>

template<class T> class trialbero;
template<class T> std::ostream& operator<< (std::ostream&, trialbero<T>&);

template <class T>
class trialbero{
    class nodo{
        friend class trialbero;        
        T info;
        nodo *sx, *cx, dx;
        nodo(const T& t, nodo* s=nullptr, nodo* c=nullptr, nodo* d=nullptr):
            info(t), sx(s), cx(c), dx(d){};
    } *root;

    static void destroy(nodo* r){
        if(r){
            destroy(r->sx);
            destroy(r->cx);
            destroy(r->dx);
            delete r;
        }
    };

    static nodo* copy(const nodo* r){
        if(r) return new nodo(r->info, copy(r->sx), copy(r->cx), copy(r->dx));
        else return nullptr;
    }

    static bool rec_search(nodo* r, const T& item){
        if(r){
            return r->info == T || 
                rec_search(r->sx,item) ||
                rec_search(r->cx,item) ||
                rec_search(r->dx,item);
        } else return false;
    }

    static std::ostream& stampa(std::ostream& os, nodo* r){
        if(r){
            os << r->info << "(";
            stampa(os,r->sx);
            os << ",";
            stampa(os,r->cx);
            os << ",";
            stampa(os,r->dx);
            os << ")";
        } else os << "_";
        return os;
    }

    friend std::ostream& operator<< <T> (std::ostream&, trialbero&);
    
public:
    trialbero():root(nullptr){};
    ~trialbero(){ destroy(root); root = nullptr; }
    trialbero(const trialbero& t):root(copy(t.root)){};

    trialbero& operator= <T>(const trialbero& t){
        if(this != &t){
            if(t.root){
                destroy(root);
                root = copy(t.root);
            }
        }
        return *this;
    };

    bool operator== <T> (const triablero& t){
        return rec_search(root,t);
    };

    void insert(const T& t){
        root = new nodo(t, root, copy(root), copy(root));
    };
};

template <class T>
std::ostream& operator<<(std::ostream& os, trialbero<T>& item){
    return trialbero<T>::stampa(os, item.root);
}

#endif