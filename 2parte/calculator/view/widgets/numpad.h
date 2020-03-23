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
    numpad(QWidget* parent = nullptr);
    ~numpad() = default;
};

#endif /* NUMPAD_H */
