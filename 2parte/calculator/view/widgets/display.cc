#include "display.h"

display::display(QWidget* parent):
	QLineEdit(parent)
{
    QLineEdit::resize(300,200);
}

void display::append(const QString& str){ return; }
