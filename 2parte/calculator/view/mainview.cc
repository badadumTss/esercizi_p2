#include "mainview.h"

mainView::mainView(QWidget* parent, model* c):
	QWidget(parent),
	core(c ? c : new model()),
	_display(new display(this)),
	_numpad(new numpad(this)),
	_funpad(new funpad(this))
{
	layout = new QGridLayout();
	layout->addWidget(_display,0,0);
	layout->addWidget(_numpad,1,0);
	layout->addWidget(_funpad,1,1);
	setLayout(layout);
}

mainView::~mainView(){
	delete core; // la distruzione degli altri elementi è affidata a Qt
	delete _display;
	delete _numpad;
	delete _funpad;
	delete layout;
}

void mainView::eval(op opt, int val) {
	switch (opt) {
	case plus:
		core->sum(val);
	case minus:
		core->diff(val);
	case times:
		core->multiply(val);
	case over:
		core->divide(val);
    default: throw InvalidExpr("exp di prova");
	};
}

void mainView::setResult() { return; }
