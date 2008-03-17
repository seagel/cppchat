/*
A fájl szerepét lásd a MyQMainWindow.h-ban. Tehát ugyanolyan jellegû
-szk 2008.03.16.

Elkezdem kitölteni a private részeket is.
De ezzel a ne nagyon törõdjetek! Nektek csak a public slots és a signals rész az érdekes.
-szk 2008.03.17.
*/
#include <QWidget>
#include <QGridLayout>


class ChatWindow: public QWidget{

	Q_OBJECT

	public slots:

		//*******************kommunikáció a main window-val*******************
		void messageReceived(String username, QString message,int connectionID);
			//connectionID azért kell ide is, mert a visszaküldénél tudni kell és akkor itt kikeres és küldi


	signals:

		void sendMessage(String username, QString message, int connectionID);
			//vagy a mainwindow, vagy a net fogja fogadni, aztán végül mindenképpen a net


	public:
		ChatWindow(QWidget *parent=NULL);


	private:
		QTextEdit historyField;					//amiben a beszélgetés eddigiei vannak
		QTextEdit activeField;					//ahova írunk



};
