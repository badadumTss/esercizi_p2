#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <vector>

class Component;

class Container {
public:
  virtual  ~Container();
  std::vector<Component*> getComponents() const;
/*  ritorna un std::vector di
    puntatori a tutte le componenti inserite nel contenitore c ;*/
};

class Component: public Container {};

class Button: public Component {
public:
  std::vector<Container*> getContainers() const;
  /*ritorna un std::vector di
    puntatori a tutti i contenitori che contengono il pulsante b ;*/
};

class MenuItem: public Button {
public:
  void setEnabled(bool b = true);
};

class NoButton {};

Button** fun(const Container& c){
  std::vector<Button*> to_return;
  std::vector<Component*> components = c.getComponents();
  for(std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); ++it){
    Button* is_button = dynamic_cast<Button*>(*it);
    if(is_button){
      to_return.push_back(new Button(*is_button));
      MenuItem* is_MenuItem = dynamic_cast<MenuItem*>(*it);
      if(is_MenuItem && (is_button->getContainers()).size() >= 2)
	is_MenuItem->setEnabled(false);
    }
  }
  if(to_return.size())
    return &(*(to_return.begin())); // a me sembra una hack, un modo meglio?
  /* return &to_return[0] // anche questa sembra una hack, forse perchè un po'bisogna farlo */
  else return nullptr;
}

#endif
