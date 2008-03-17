/*
Ez a f�jl ir�nymutat�nak szolg�l arra, hogy a QMainWindow class hogyan tud a k�rnyezet�vel kommunik�lni. Teljesen nincs k�sz mindenki nyugodtan szerkessze. Igaz�b�l �tletek szintj�n mozog, nagyj�b�l arra j�, hogy a gondolatokat �sszefogja. Egyel�re teh�t csak a slotot-b�l �s a signal-okb�l lesz n�h�ny. Pr�b�lok min�l besz�desebb nevet �rni mindenhova, sz�ljatok ha valami nem vil�gos. Err�l jut eszembe: a naming convention-t meg k�ne besz�lni (azt is :D). ->t�nyleg magyar vagy angol?
Megjegyz�s: a sok helyen m�g a t�pus�t sem �rom oda a param�ternek, jelezve, hogy nincs kidolgozva az a r�sz m�g: pl. milyen form�tumban kapjuk meg a kontakt list�t
A MyQMainWindow a f�ablak lesz (lehetne valami frappnsabb n�v): teh�t contact list, �llapot, le�r�s, stb. kezel�s�re val�.
-szk 2008.03.16.
*/



class MyQMainWindow: public QMainWindow{
	
	Q_OBJECT
	
	public slots:	//lehet, hogy a private is el�g...
		
		//*******************ezek a net libraryval val� kommunik�ci�ra lesznek*******************
		void connected(contactList);								
			//ha csatlakozott akkor megkapja a kontact listet
			
		void connectionChanged(int state);
			
		void newPartnerAttemp(String username, QString name, QString description);	
			//valaki felvett a partnerlist�j�ra-a; a username, amivel bejelentkezik, a name ami megjelenik
			//a QString az unicode, a username-re el�g a sima ascii is
	
		void someonesStateChanged(String username, int newState);				
			//a state-be tartozik a login, logoff is
			
		void someonesNameChanged(String username, QString newName);
		void someonesDescriptionChanged(String username, QString newDescreption);
		void messageReceived(String username, QString message, int connectionID);		
			//username: kit�l; connectionID: gondolom, hogy ha t�bb ablakban valaki(sima+group), akkor az t�bb connection-ben van,
			//teh�t, ennek az id-je kell, hogy tudjuk melyik ablakba kell rakni az �zenetet
			
	
	signals:
		
		//*******************ezeket els�rorban a net librarynak k�ldi*******************
		void connect(String username, String passwd);
			//Attemp to connect
	
		void myStateChanged(int newState);
		void myNameChanged(String newName);
		void myDescriptionChanged(QString newDescription);
		
		void acceptUser(QString username);
			//magyar�n felveszem a partnerlist�ra
	
		void initiateUser(String name);
			//jobb nevet! teh�t felveszem partnernek
			
			
		//*******************�zenetek a ChatWindow-oknak ******************* 
			//- ha ezek a nett�l j�v�nek t�nnek, akkor �gy megy, hogy ezeket tov�bb�tja a chatwindowoknak
		void messageToWindow(String username, QString message, int connectionID); 		
			//jobb nevet!  - egy ablakhoz tov�bbitja az �zenetet ( a rendszer el�bb l�trehozza az ablakot ha az nincs)
		
		
		
};
