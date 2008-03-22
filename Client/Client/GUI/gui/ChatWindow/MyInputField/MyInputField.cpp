/*csak nekem �rdekes egyel�re:
-szk 2008. 03.19
*/

#include "ChatWindow\MyInputField\MyInputField.h"
#include <windows.h>
void MyInputField::keyPressEvent(QKeyEvent *event){


	if(Qt::Key_Return==event->key() && Qt::ShiftModifier!=event->modifiers()){
		//teh�t ha entert nyomtak, �gy hogy shift n�lk�l, akkor �zenet k�ld�s
		if(0<toPlainText().size()){//de csak akkor ha van mit
			emit enterPressed(toPlainText());//ha nem html-t akarunk
			setPlainText("");
		}
	}else{
		QTextEdit::keyPressEvent(event);
	}
}
