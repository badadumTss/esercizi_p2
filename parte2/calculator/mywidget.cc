#include "mywidget.h"
#include "inputbuttons.h"
// #include <QMessageBox>
#include <QInputDialog>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget* parent):QWidget(parent){
	resize(500,300);
	QInputDialog* results = new QInputDialog(this);
	results->setOption(QInputDialog::NoButtons);
	// QMessageBox* results = new QMessageBox(this);
	// results->resize(500,100);
	inputButtons* theButtons = new inputButtons(this);
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(results); layout->addWidget(theButtons);
	setLayout(layout);
}
