#include <QApplication>
#include "view/mainview.h"

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	mainView mainWindow;
	mainWindow.show();
	return app.exec();
}
