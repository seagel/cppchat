/*
A fájl szerepét lásd a MyQMainWindow.h-ban. Tehát ugyanolyan jellegû
-szk 2008.03.16.

Elkezdem kitölteni a private részeket is.
De ezzel a ne nagyon törõdjetek! Nektek csak a public slots és a signals rész az érdekes.
-szk 2008.03.17.

A stringeket kicseréltem mind QString-re, mivel problémás a konvertálás string és QString közt, egyszerûbb, ha minden QString
-szk 2008.03.18.
*/
#ifndef CHAT_WINDOW
#define CHAT_WINDOW
#include <QWidget>
#include <QGridLayout>
#include <QSplitter>

#include <QTextEdit>
#include "ChatWindow\MyInputField\MyInputField.h"

class ChatWindow: public QWidget{

	Q_OBJECT

	public slots:

		//*******************kommunikáció a main window-val vagy a netHandlerrel*******************
		void messageReceived(QString username, QString message);
			//connectionID azért kell ide is, mert a visszaküldénél tudni kell és akkor itt kikeres és küldi

		void newPartnerConnected(QString username, int connectionId);
		void partnerStateChanged(QString name, int newState);//kijelentkezett is idetartozik

	private slots:
		void inputReceived(QString input);//önmagamtól az inputfielden keresztül

	signals:

		void sendMessage(QVector<int> connectionIds,  QString message);
			//connection ID: elvileg minden emberhez van egy
			//vagy a mainwindow, vagy a net fogja fogadni, aztán végül mindenképpen a net

		//private signalok:
			void appendMessage(QString message);

	public:
		ChatWindow(QWidget *parent=NULL,QString username="szk");


	private:
		QTextEdit historyField;					//amiben a beszélgetés eddigiei vannak
		MyInputField activeField;				//ahova írunk
		QString myUsername;
		QMap<int,QString> idUsernamePair;		//melyik netkapcsolatohoz mely felhasználó van az adott ablakon belül



};
#endif
