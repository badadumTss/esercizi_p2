#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>

class MyWidget: public QWidget{
//	QObject::Q_OBJECT
public:
	MyWidget(QWidget* parent = Q_NULLPTR);
};

#endif /* MYWIDGET_H */
