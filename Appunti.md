# Cosa serve:

## STL:
 - std::vector
 - std::list
 ...
 - std:queue

Di ognuno sapere vantaggi e svantaggi in performance nei vari scenari

## Per gli esercizi:
 - **Ereditarietà**:
  - _public, private e protected_: cosa fanno nell'albero delle classi
  - _derivazione con virtual_: separazione tra compile-time e run-time
 - **Buone pratiche**:
  - _distruttore virtuale_: più che una buona pratica un caldo obbligo per le classi di base
  - _Metodo BASE* Clone()_: nessun distruttore di copia virtuale? nessun probelma!!
  - _FUNZIONI POLIMORFE_: se devi usare dynamic_cast nel main hai una gerarchia di merda
  - _attenzione ai costruttori_: spesso non li chiede e non serve implementarli, SOPRATTUTO SE SONO DI DEFAULT
  - _Contenitori di puntatori_: qui occhio alle distruzioni: quelle di default sono profonde ma per gli oggetti dentro, se hai puntatori come tipi devi distruggerli tu!!
  - _Sii ragionevole nei nomi_: e nei tipi, ma per quelli non dovrebbe essere schizzinoso o altre funzioni possono fare da hint sui tipi

## differenze iteratori e const_iterator:
I tipi di ritorno sugli oggetti!

- iterator (1):
	 T& operator\*() const { return \*ptr; }
	 T\* operator->() const { return ptr; }

- const_iterator:
	 const T& operator\*() const { return \*ptr; }
	 const T\* operator->() const { return ptr; }

## Cast dinamici e statici:
- **dinamici**:
  da usare se ho puntatore alla classe base e 'voglio vedere' se l'oggetto puntato appartiene a uno specifico sottoalbero di sottoclassi
  compile-time:
