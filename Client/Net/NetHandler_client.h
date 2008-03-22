/*
Tudom, hogy nem az eny�m, nem is akarok nagyon belekont�rkodni, csak a publikus r�sz�re javaslatokat teszek, mint a MyQMainWindow.h-hoz.
Egyel�re f�leg csak a mainWindow-val folytatott komunk�ci�ra �szpontos�tok. Ja �s a n�v se tetszik, csak nem volt jobb.
Ja �s az�rt van k�l�n kliens mert szerintem nagyon m�s lesz a kett�, legal�bbis az interface r�sze.
-szk 2008.03.16.
*/

class NetHandler:public Qvalami{

	Q_OBJECT


	public slots:
		//*******************ezek nagyj�b�l egy az egyben a QMainWindow fel� a cuccok, magyar�zatok ott*******************
		void connect(String username, String passwd);

		void myStateChanged(int newState);
			//lehet, hogy jobb lenne: userStateChanged(
		void myNameChanged(String newName);
		void myDescriptionChanged(QString newDescription);

		void acceptUser(QString username);
		void initiateUser(String name);

		void sendMessage(String username, QString message, int connectionID);


	signals:
		//ezek gyakorlatilag egy az egyben a MyQMainWindow m�sik oldalai(signaljai)-> �ltal�ban n�vegyez�ssel.
		// Magyar�zatokat kiszedtem ld. MyQMainWindow

		//*******************MyQMainWiindow-val kom.*******************
		void connected(contactList);
		void connectionChanged(int state);

		void newPartnerAttemp(String username, QString name, QString description);

		void someonesStateChanged(String username, int newState);
		void someonesNameChanged(String username, QString newName);
		void someonesDescriptionChanged(String username, QString newDescreption);

		void messageReceived(String username, QString message, int connectionID);

};
