/*
Ez a f�jl ir�nymutat�nak szolg�l arra, hogy a QMainWindow class hogyan tud a k�rnyezet�vel kommunik�lni. Teljesen nincs k�sz mindenki nyugodtan szerkessze. Igaz�b�l �tletek szintj�n mozog, nagyj�b�l arra j�, hogy a gondolatokat �sszefogja. Egyel�re teh�t csak a slotot-b�l �s a signal-okb�l lesz n�h�ny. Pr�b�lok min�l besz�desebb nevet �rni mindenhova, sz�ljatok ha valami nem vil�gos. Err�l jut eszembe: a naming convention-t meg k�ne besz�lni (azt is :D). ->t�nyleg magyar vagy angol?
Megjegyz�s: a sok helyen m�g a t�pus�t sem �rom oda a param�ternek, jelezve, hogy nincs kidolgozva az a r�sz m�g: pl. milyen form�tumban kapjuk meg a kontakt list�t
A MyQMainWindow a f�ablak lesz (lehetne valami frappnsabb n�v): teh�t contact list, �llapot, le�r�s, stb. kezel�s�re val�.
-szk 2008.03.16.
*/
#ifndef MYMAIN
#define MYMAIN
#include <QWidget>
#include <QMainWindow>
#include <String>
#include <QMenu>
#include <QAction>
#include "MySignInWidget\MySignInWidget.h"
#include "ConfigHandler\ConfigHandler.h"




class MyMainWindow: public QMainWindow{

	Q_OBJECT


	public:
		MyMainWindow(QWidget *parent=0,Qt::WindowFlags flags = 0);
		void changeToSignInWindow();
			//nem vagyok benne biztos, hogy hova rakjam: itt a logikus, vagy slotk�n: v�g�lis ott akkor nem  kell r� v�rni


	public slots:	//lehet, hogy a private is el�g...

		//*******************ezek a net libraryval val� kommunik�ci�ra lesznek*******************
		//void connected(contactList);
			//ha csatlakozott akkor megkapja a kontact listet

		void myConnectionChanged(int state);//pl. megszakadt pl a kapcsolat, vagy l�trej�tt

		void newPartnerAttempt(const QString &username,const QString &name, const QString &description);
			//valaki felvett a partnerlist�j�ra-a; a username, amivel bejelentkezik, a name ami megjelenik
			//a QString az unicode, a username-re el�g a sima ascii is

		void someonesStateChanged(const QString &username, int newState);
			//a state-be tartozik a login, logoff is

		void someonesNameChanged(const QString &username, const QString &newName);
		void someonesDescriptionChanged(const QString &username, const QString &newDescreption);
		void messageReceived(const QString &username, const QString &message, int connectionID);
			//username: kit�l; connectionID: gondolom, hogy ha t�bb ablakban valaki(sima+group), akkor az t�bb connection-ben van,
			//teh�t, ennek az id-je kell, hogy tudjuk melyik ablakba kell rakni az �zenetet

		void loginAttempt(const QString &username, const QString &password, bool saveData);


	signals:

		//*******************ezeket els�rorban a net librarynak k�ldi*******************
		void logInAttempt(std::string username, std::string passwd);
			//Attemp to connect

		void myStateChanged(int newState);//sz�nd�kos kapcsolatv�lt�s(�ltal�ban)
		void myNameChanged(QString newName);//megv�ltoztatom
		void myDescriptionChanged(QString newDescription);//megv�ltoztatom

		void acceptUser(QString username);
			//magyar�n felveszem a partnerlist�ra

		void initiateUser(QString name);
			//jobb nevet! teh�t felveszem partnernek - m�rmint megpr�b�lom


		//*******************�zenetek a ChatWindow-oknak *******************
			//- ha ezek a nett�l j�v�nek t�nnek, akkor �gy megy, hogy ezeket tov�bb�tja a chatwindowoknak
		void messageToWindow(QString username, QString message, int connectionID);
			//jobb nevet!  - egy ablakhoz tov�bbitja az �zenetet ( a rendszer el�bb l�trehozza az ablakot ha az nincs)


	private:
		MySignInWidget *signInWidget;
		ConfigHandler *generalConfig;




};


#endif
