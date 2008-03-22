/*
A f�jl szerep�t l�sd a MyQMainWindow.h-ban. Teh�t ugyanolyan jelleg�
-szk 2008.03.16.

Elkezdem kit�lteni a private r�szeket is.
De ezzel a ne nagyon t�r�djetek! Nektek csak a public slots �s a signals r�sz az �rdekes.
-szk 2008.03.17.

A stringeket kicser�ltem mind QString-re, mivel probl�m�s a konvert�l�s string �s QString k�zt, egyszer�bb, ha minden QString
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

		//*******************kommunik�ci� a main window-val vagy a netHandlerrel*******************
		void messageReceived(QString username, QString message);
			//connectionID az�rt kell ide is, mert a visszak�ld�n�l tudni kell �s akkor itt kikeres �s k�ldi

		void newPartnerConnected(QString username, int connectionId);
		void partnerStateChanged(QString name, int newState);//kijelentkezett is idetartozik

	private slots:
		void inputReceived(QString input);//�nmagamt�l az inputfielden kereszt�l

	signals:

		void sendMessage(QVector<int> connectionIds,  QString message);
			//connection ID: elvileg minden emberhez van egy
			//vagy a mainwindow, vagy a net fogja fogadni, azt�n v�g�l mindenk�ppen a net

		//private signalok:
			void appendMessage(QString message);

	public:
		ChatWindow(QWidget *parent=NULL,QString username="szk");


	private:
		QTextEdit historyField;					//amiben a besz�lget�s eddigiei vannak
		MyInputField activeField;				//ahova �runk
		QString myUsername;
		QMap<int,QString> idUsernamePair;		//melyik netkapcsolatohoz mely felhaszn�l� van az adott ablakon bel�l



};
#endif
