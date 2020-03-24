#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "../model/model.h"
#include "../model/hierachy/exeptions.h"
#include "widgets/display.h"
#include "widgets/numpad.h"
#include "widgets/funpad.h"
#include <QWidget>
#include <QString>
#include <QGridLayout>

enum op {plus, minus, times, over}; 

class mainView: public QWidget{
Q_OBJECT
private:
	model* core; // interfaccia per la gerarchia
	display* _display;
	numpad* _numpad;
	funpad* _funpad;
	QGridLayout* layout;
public:
	mainView(QWidget* parent = Q_NULLPTR, model* c = nullptr);
	~mainView();
public slots:
	void eval(op opt, int val);
	void setResult();
};

#endif /* MAINVIEW_H */
