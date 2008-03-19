/*Csak kikinek érdekes:
-szk 2008.03.19
*/
#ifndef MY_INPUT_FIELD
#define MY_INPUT_FIELD

#include <QTextEdit>
#include <QString>
#include <QKeyEvent>
class MyInputField:public QTextEdit{

	Q_OBJECT

	protected:
		void keyPressEvent(QKeyEvent *event);

	signals:
		void enterPressed(QString message);

};


#endif
