/* 
A f�jl szerep�t l�sd a MyQMainWindow.h-ban. Teh�t ugyanolyan jelleg�
-szk 2008.03.16.
*/

class ChatWindow: public Qvalami{
	
	Q_OBJECT
	
	public slots:
		
		//*******************kommunik�ci� a main window-val*******************
		void messageReceived(String username, QString message,int connectionID);
			//connectionID az�rt kell ide is, mert a visszak�ld�n�l tudni kell �s akkor itt kikeres �s k�ldi
	
	signals:
	
		void sendMessage(String username, QString message, int connectionID);
			//vagy a mainwindow, vagy a net fogja fogadni, azt�n v�g�l mindenk�ppen a net
	
};