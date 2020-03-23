#ifndef FUNPAD_H
#define FUNPAD_H
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class funpad: public QWidget{
	Q_OBJECT
	// signals:
public:
	funpad(QWidget* parent = Q_NULLPTR);
    ~funpad() = default;
};

#endif /* FUNPAD_H */
