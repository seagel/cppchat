/* A MySignInWidget
az a terület ami a bejelentkezéskot van: ilyenkor a mainwindow centerwidgete ez.
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

		QString getUsernameField();//a config-tároláshoz
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
			//azért nem rögtön a nethez megy, mert a mainwindow kezel minden ehhez kapcsolódó dolgot


};


#endif
