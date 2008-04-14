#include "MySignInWidget.h"

MySignInWidget::MySignInWidget(QWidget *parent):QWidget(parent){
	const int LAST_ROW=5;
	const int LAST_COL=5;
	qDebug("Creating MySignInWidget...");
	QGridLayout *layout=new QGridLayout();
	usernameField=new QLineEdit;
	passwordField=new QLineEdit;
	rememberDataCheckBox=new QCheckBox("Remember username and password");
	loginButton=new QPushButton("Log in");

	connect(loginButton,SIGNAL(clicked()), this, SLOT(loginButtonPressed()));

	passwordField->setEchoMode(QLineEdit::Password);

	layout->setRowMinimumHeight(0,100);
	layout->addWidget(usernameField,1,1,1,3);
	layout->addWidget(passwordField,2,1,1,3);
	layout->addWidget(rememberDataCheckBox,3,1,1,3);
	layout->addWidget(loginButton,4,2,1,1);

	layout->setRowMinimumHeight(LAST_ROW,100);

	layout->setColumnMinimumWidth(0,100);
	layout->setColumnMinimumWidth(LAST_COL,100);

	layout->setRowStretch(0,1);
	layout->setRowStretch(LAST_ROW,1);
	layout->setColumnStretch(0,1);
	layout->setColumnStretch(LAST_COL,1);

	this->setLayout(layout);
}
void MySignInWidget::loginButtonPressed(){
	qDebug("Login started...");
	bool checkState;
	if(0==rememberDataCheckBox->checkState()){
		checkState=false;
	}else{
		checkState=true;
	}
	loginButton->setText("Logging in...");
	loginButton->setEnabled(false);
	emit loginAttempt(usernameField->text(), passwordField->text(),checkState);

}



QString MySignInWidget::getPasswordField(){
	return passwordField->text();
}

void MySignInWidget::setPasswordField(const QString new_password){
	passwordField->setText(new_password);
}

QString MySignInWidget::getUsernameField(){
	return usernameField->text();
}

void MySignInWidget::setUsernameField(const QString new_username){
	usernameField->setText(new_username);
}

void MySignInWidget::setRememberDataCheckBox(QString state){
	if("0"==state){
		rememberDataCheckBox->setCheckState(Qt::Unchecked);
	}else{
		rememberDataCheckBox->setCheckState(Qt::Checked);
	}
}

