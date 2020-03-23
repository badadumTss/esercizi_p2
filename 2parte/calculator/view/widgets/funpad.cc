#include "funpad.h"

funpad::funpad(QWidget* parent):
	QWidget(parent)
{
    QGridLayout* layout = new QGridLayout();
	QPushButton* plus = new QPushButton(QString("+"),this);
	QPushButton* minus = new QPushButton(QString("-"),this);
	QPushButton* times = new QPushButton(QString("x"),this);
	QPushButton* divide = new QPushButton(QString("/"),this);
	QPushButton* equal = new QPushButton(QString("="),this);

	layout->addWidget(plus, 0, 0);
	layout->addWidget(minus, 0, 1);
	layout->addWidget(times, 1, 0);
	layout->addWidget(divide, 1, 1);
    layout->addWidget(equal, 2, 0, 2, 0);

	setLayout(layout);
}
