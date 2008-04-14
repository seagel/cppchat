/* A MySignInWidget
az a ter�let ami a bejelentkez�skot van: ilyenkor a mainwindow centerwidgete ez.
*/

#ifndef MY_SIGN_IN
#define MY_SIGN_IN

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

class MySignInWidget: public QWidget{
	Q_OBJECT

	public:
		MySignInWidget(QWidget *parent=NULL);

		QString getUsernameField();//a config-t�rol�shoz
		void setUsernameField(QString new_username);

		QString getPasswordField();
		void setPasswordField(QString new_password);

		void setRememberDataCheckBox(QString state);

	private:
		QLineEdit *usernameField;
		QLineEdit *passwordField;
		QCheckBox *rememberDataCheckBox;
		QPushButton *loginButton;

	private slots:
		void loginButtonPressed();

	signals:
		void loginAttempt(QString username, QString password,bool saveData);
			//az�rt nem r�gt�n a nethez megy, mert a mainwindow kezel minden ehhez kapcsol�d� dolgot


};


#endif
