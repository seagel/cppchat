/*
Tudom, hogy nem az enyém, nem is akarok nagyon belekontárkodni, csak a publikus részére javaslatokat teszek, mint a MyQMainWindow.h-hoz.
Egyelõre fõleg csak a mainWindow-val folytatott komunkációra öszpontosítok. Ja és a név se tetszik, csak nem volt jobb.
Ja és azért van külön kliens mert szerintem nagyon más lesz a kettõ, legalábbis az interface része.
-szk 2008.03.16.
*/

class NetHandler:public Qvalami{

	Q_OBJECT


	public slots:
		//*******************ezek nagyjából egy az egyben a QMainWindow felé a cuccok, magyarázatok ott*******************
		void connect(String username, String passwd);

		void myStateChanged(int newState);
			//lehet, hogy jobb lenne: userStateChanged(
		void myNameChanged(String newName);
		void myDescriptionChanged(QString newDescription);

		void acceptUser(QString username);
		void initiateUser(String name);

		void sendMessage(String username, QString message, int connectionID);


	signals:
		//ezek gyakorlatilag egy az egyben a MyQMainWindow másik oldalai(signaljai)-> általában névegyezéssel.
		// Magyarázatokat kiszedtem ld. MyQMainWindow

		//*******************MyQMainWiindow-val kom.*******************
		void connected(contactList);
		void connectionChanged(int state);

		void newPartnerAttemp(String username, QString name, QString description);

		void someonesStateChanged(String username, int newState);
		void someonesNameChanged(String username, QString newName);
		void someonesDescriptionChanged(String username, QString newDescreption);

		void messageReceived(String username, QString message, int connectionID);

};
