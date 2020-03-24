#ifndef NUMPAD_H
#define NUMPAD_H
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class numpad: public QWidget{
Q_OBJECT
// signals:
//     void expr(op opt, int val);
public:
    numpad(QWidget* parent = nullptr):
		QWidget(parent)
		{
			QGridLayout* layout1 = new QGridLayout(this);
			for(int i=0; i<3; ++i)
				for(int j=0; j<3; ++j){
					QPushButton* num = new QPushButton(QString::number(i*3+j+1),this);
					num->resize(30,30);
					layout1->addWidget(num, i, j);
				}
			setLayout(layout1);
		}

	virtual ~numpad() = default;
};
#endif /* NUMPAD_H */
