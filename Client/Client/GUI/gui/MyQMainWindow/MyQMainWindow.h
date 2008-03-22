/*
Ez a fájl iránymutatónak szolgál arra, hogy a QMainWindow class hogyan tud a környezetével kommunikálni. Teljesen nincs kész mindenki nyugodtan szerkessze. Igazából ötletek szintjén mozog, nagyjából arra jó, hogy a gondolatokat összefogja. Egyelõre tehát csak a slotot-ból és a signal-okból lesz néhány. Próbálok minél beszédesebb nevet írni mindenhova, szóljatok ha valami nem világos. Errõl jut eszembe: a naming convention-t meg kéne beszélni (azt is :D). ->tényleg magyar vagy angol?
Megjegyzés: a sok helyen még a típusát sem írom oda a paraméternek, jelezve, hogy nincs kidolgozva az a rész még: pl. milyen formátumban kapjuk meg a kontakt listát
A MyQMainWindow a fõablak lesz (lehetne valami frappnsabb név): tehát contact list, állapot, leírás, stb. kezelésére való.
-szk 2008.03.16.
*/
#ifndef MYQMAIN
#define MYQMAIN
#include <QWidget>
#include <String>


//csak azért kell, hgy tudjak fordítani - tehát egyelõre ezt a részt nem fordítja
#ifdef HAS_MYQMAIN


class MyQMainWindow: public QMainWindow{

	Q_OBJECT

	public slots:	//lehet, hogy a private is elég...

		//*******************ezek a net libraryval való kommunikációra lesznek*******************
		//void connected(contactList);
			//ha csatlakozott akkor megkapja a kontact listet

		void myConnectionChanged(int state);

		void newPartnerAttemp(std::string username, QString name, QString description);
			//valaki felvett a partnerlistájára-a; a username, amivel bejelentkezik, a name ami megjelenik
			//a QString az unicode, a username-re elég a sima ascii is

		void someonesStateChanged(std::string username, int newState);
			//a state-be tartozik a login, logoff is

		void someonesNameChanged(std::string username, QString newName);
		void someonesDescriptionChanged(std::string username, QString newDescreption);
		void messageReceived(std::string username, QString message, int connectionID);
			//username: kitöl; connectionID: gondolom, hogy ha több ablakban valaki(sima+group), akkor az több connection-ben van,
			//tehát, ennek az id-je kell, hogy tudjuk melyik ablakba kell rakni az üzenetet


	signals:

		//*******************ezeket elsõrorban a net librarynak küldi*******************
		void connect(std::string username, std::string passwd);
			//Attemp to connect

		void myStateChanged(int newState);
		void myNameChanged(std::string newName);
		void myDescriptionChanged(QString newDescription);

		void acceptUser(QString username);
			//magyarán felveszem a partnerlistára

		void initiateUser(std::string name);
			//jobb nevet! tehát felveszem partnernek - mármint megpróbálom


		//*******************üzenetek a ChatWindow-oknak *******************
			//- ha ezek a nettõl jövõnek tûnnek, akkor úgy megy, hogy ezeket továbbítja a chatwindowoknak
		void messageToWindow(std::string username, QString message, int connectionID);
			//jobb nevet!  - egy ablakhoz továbbitja az üzenetet ( a rendszer elõbb létrehozza az ablakot ha az nincs)



};
#endif

#endif
