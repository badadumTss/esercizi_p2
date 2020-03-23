#include "mainview.h"

mainView::mainView(QWidget* parent, model* c):
	QWidget(parent),
	core(c ? c : new model()),
	_display(new display(this)),
	_numpad(new numpad(this)),
	_funpad(new funpad(this))
{}

mainView::~mainView(){
	delete core; // la distruzione degli altri elementi è affidata a Qt
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
