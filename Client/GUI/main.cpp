/* A program ezen része általában senkinek nem érdekes*/
/*egyelõre nem müxik rendesen, csak a chat ablakot próbálja ki
-szk 2008.03.18*/

#include <QApplication>
#include "MyMainWindow\MyMainWindow.h"
#include "ChatWindow\ChatWindow.h"

int main(int argc, char *argv[]){
	qDebug("Starting program: main");
	QApplication app(argc, argv);
	MyMainWindow mainWindow;
	mainWindow.show();
	mainWindow.changeToSignInWindow();
	mainWindow.resize(500,500);
	//ChatWindow chat;
	//chat.show();
	return app.exec();
}
