#include "inputbuttons.h"
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <iostream>

inputButtons::inputButtons(QWidget* parent):QWidget(parent){

	QGridLayout* grid = new QGridLayout;
	QString symbols = "123+456-789x 0 /";
	for(int row=0; row<4; ++row)
		for (int col=0; col<4; ++col) {
			if(symbols[(row*4)+(col)] != ' '){
				QPushButton* button = new QPushButton(QString(symbols[(row*4)+(col)]),this);
				button->resize(50,50);
				grid->addWidget(button, row, col);
			}
		}
	grid->setSizeConstraint(QLayout::SetMinAndMaxSize);
	setLayout(grid);
};
