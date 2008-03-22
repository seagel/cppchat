/*csak nekem érdekes egyelõre:
-szk 2008. 03.19
*/

#include "ChatWindow\MyInputField\MyInputField.h"
#include <windows.h>
void MyInputField::keyPressEvent(QKeyEvent *event){


	if(Qt::Key_Return==event->key() && Qt::ShiftModifier!=event->modifiers()){
		//tehát ha entert nyomtak, úgy hogy shift nélkül, akkor üzenet küldés
		if(0<toPlainText().size()){//de csak akkor ha van mit
			emit enterPressed(toPlainText());//ha nem html-t akarunk
			setPlainText("");
		}
	}else{
		QTextEdit::keyPressEvent(event);
	}
}
