#ifndef HEADER_H
#define HEADER_H
#include <iostream>

template <class T> class queue;

template <class T> std::ostream& operator<<(std::ostream&, const queue<T>&);

template <class T>
class queueItem{
    T info;
    public:
        queueItem(const T&);
        queueItem* next;
    friend class queue<T>;
    friend std::ostream& operator<< <T>(std::ostream&, const queue<T>&);
};

template <class T>
class queue{
    queueItem<T> *inizio, *fine;
public:
    queue();
    ~queue();

    bool empty();
    queue<T>& add(const T&);
    T remove();
    friend std::ostream& operator<< <T>(std::ostream&, const queue<T>&);
};

template <class T> queueItem<T>::queueItem(const T& item):info(item),next(0){}

template <class T> queue<T>::queue():inizio(0),fine(0){}

template <class T> queue<T>::~queue(){
    queueItem<T>* tmp = inizio;
    while(tmp){
        inizio = inizio->next;
        delete tmp;
        tmp = inizio;
    }
    fine = 0;
}

template <class T> bool queue<T>::empty(){
    return inizio == nullptr;
}

template <class T> queue<T>& queue<T>::add(const T& item){
    if(empty()){
        inizio = fine = new queueItem<T>(item);
    } else {
        fine->next = new queueItem<T>(item);
        fine = fine->next; 
    }
    return *this;
}

template <class T> T queue<T>::remove(){
    if(this->empty()){
        std::cerr << "remove() su queue vuota" << std::endl;
        exit(1);
        /*DA NON FARE, per ora si perchè non abbiamo visto le eccezioni*/
    }
    T aux = inizio->info;
    queueItem<T>* tmp = inizio;
    inizio = inizio->next;
    delete tmp;
    if(this->empty()) fine = 0;
    return aux;
}

template <class T>
std::ostream& operator<<(std::ostream& os,const queue<T>& item){
    if(item.inizio){
        queueItem<T>* tmp = item.inizio;
        while(tmp != item.fine){
            os << tmp->info << " -> ";
            tmp = tmp->next;
        }
        os << tmp->info;
    }
    return os;    
}
#endif