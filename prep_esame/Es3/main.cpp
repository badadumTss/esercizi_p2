// #include "components.h"
class Component;

class Component: public Container {};

class Container {
public:
  virtual ~Container();
  std::vector<Component*> getComponents() const; // ritorna un std::vector di puntatori a tutte le componenti inserite nel contenitore c
};

class Button: public Component {
public:
  std::vector<Container*> getContainers() const; // ritorna un std::vector di puntatori a tutti i contenitori che contengono il pulsante b
};

class MenuItem: public Button {
public:
  void setEnabled(bool b = true); /* Il comportamento del metodo setEnabled() della classe MenuItem è il seguente: mi.setEnabled(b)
				     abilita (con b==true ) o disabilita (con b==false ) l’entrata di menu mi */
};

class NoButton {};

Button** Fun(const Container& c){
  std::vector<Button*> to_return;
  std::vector<const Component*> comps = c.getComponents();
  /*La funzione getContainers!! la .size()*/
  for(std::vector<const Component*>::const_iterator it = comps.begin(); it != comps.end(); ++it){
    const Button* current = dynamic_cast<const Button*>(*it);
    if(current){
      to_return.push_back(current);
      const MenuItem* isMenu = dynamic_cast<const MenuItem*>(current);
      if(isMenu && (current->getContainers()).size() > 1){
	isMenu->setEnabled(false);
      }
    }
  }
  to_return.shrink_to_fit();
  return (to_return.size()>0 ? &(to_return[0]) : nullptr);
}

