/* 
A fájl szerepét lásd a MyQMainWindow.h-ban. Tehát ugyanolyan jellegû
-szk 2008.03.16.
*/

class ChatWindow: public Qvalami{
	
	Q_OBJECT
	
	public slots:
		
		//*******************kommunikáció a main window-val*******************
		void messageReceived(String username, QString message,int connectionID);
			//connectionID azért kell ide is, mert a visszaküldénél tudni kell és akkor itt kikeres és küldi
	
	signals:
	
		void sendMessage(String username, QString message, int connectionID);
			//vagy a mainwindow, vagy a net fogja fogadni, aztán végül mindenképpen a net
	
};