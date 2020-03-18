#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template <class T> class Queue;

template <class T> std::ostream& operator<< (std::ostream&, const Queue<T>&);

template <class T>
class Queue{

    class queueItem{
    public:
        T info;
        queueItem *next;
        queueItem(const T&);

        friend std::ostream& operator<< <T> (std::ostream&, const Queue<T>&); 
        friend T Queue<T>::remove();
    } *primo, *ultimo;

public:

    Queue();
    ~Queue();
    
    friend std::ostream& operator<< <T> (std::ostream&, const Queue<T>&);    

    bool empty();
    Queue<T>& add(const T&);
    T remove();
};

template <class T>
Queue<T>::queueItem::queueItem(const T& item):info(item),next(0){}

template <class T>
Queue<T>::Queue():primo(0),ultimo(0){}

template <class T>
Queue<T>::~Queue(){
    while(!empty()){
        typename Queue<T>::queueItem* tmp = primo;
        primo = primo->next;
        delete tmp;
    }
}

template <class T>
bool Queue<T>::empty(){
    return !primo;
}

template <class T>
Queue<T>& Queue<T>::add(const T& item){
    if(empty()){
        primo = ultimo = new queueItem(item);
    } else {
        ultimo->next = new queueItem(item);
        ultimo = ultimo->next;
    }
    return *this;
}

template <class T>
T Queue<T>::remove(){
    if(!empty()){
        typename Queue<T>::queueItem* tmp = primo;
        primo = primo->next;
        tmp->next = 0;
        if(empty()){
            ultimo = 0;
        }
        return tmp->info;
    } else {
        std::cerr << "remove() su lista vuota" << std::endl;
        exit(1);
        /*
        COMPORTAMENTO NON ACCETTABILE, ma per ora bisogna fare così dato che non abbiamo ancora 
        visto le eccezzioni nei metodi di classe
        */
    }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q){
    typename Queue<T>::queueItem * tmp = q.primo;
    while(tmp){
        os << tmp->info;
        if(tmp->next) os << " -> ";
        tmp = tmp->next;
    }
    return os;
}

#endif
