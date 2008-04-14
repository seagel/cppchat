#include "MyMainWindow.h"


MyMainWindow::MyMainWindow(QWidget *parent,Qt::WindowFlags flags ):
										QMainWindow(parent,flags){

	generalConfig=new ConfigHandler("general.conf");




}


void MyMainWindow::changeToSignInWindow(){
	qDebug("Changing to sign in widget");
	signInWidget=new MySignInWidget(); //azért itt mert nem kell mindig a memóriban tartani
	signInWidget->setUsernameField(generalConfig->getField("usernameField"));
	signInWidget->setPasswordField(generalConfig->getField("passwordField"));
	signInWidget->setRememberDataCheckBox(generalConfig->getField("saveDataCheckBoxState"));
	setCentralWidget(signInWidget);
	connect(signInWidget,SIGNAL(loginAttempt(QString,QString,bool)),this,SLOT(loginAttempt(QString, QString,bool)));
}


void MyMainWindow::myConnectionChanged(int state){
}
void MyMainWindow::newPartnerAttempt(const QString &username,const QString &name,const QString &description){
}
void MyMainWindow::someonesStateChanged(const QString &username, int newState){
}
void MyMainWindow::someonesNameChanged(const QString &username,const QString &newName){
}
void MyMainWindow::someonesDescriptionChanged(const QString &username,const QString &newDescreption){
}
void MyMainWindow::messageReceived(const QString &username,const QString &message, int connectionID){
}

void MyMainWindow::loginAttempt(const QString &username,const QString &password, bool saveData){
	if(saveData){
		generalConfig->setField("usernameField",username);
		generalConfig->setField("passwordField",password);
		generalConfig->setField("saveDataCheckBoxState",(QString)saveData);
		generalConfig->save();
	}

}


