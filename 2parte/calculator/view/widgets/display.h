#ifndef DISPLAY_H
#define DISPLAY_H
#include <QLineEdit>

class display: public QLineEdit{
Q_OBJECT
public:
	display(QWidget* parent);
    ~display() = default;
	void append(const QString& str);
};

#endif /* DISPLAY_H */
