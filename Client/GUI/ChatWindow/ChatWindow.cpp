/*
Nem fontos, csak nekem.
-szk 2008. 03.17
*/

#include "ChatWindow.h"

ChatWindow::ChatWindow(QWidget *parent,QString username): QWidget(parent){

	qDebug("Setting up ChatWindow");

	myUsername=username;

	//setting up layout
	QVBoxLayout *vBoxLayout=new QVBoxLayout();
	activeField.setMinimumHeight(30);
	QSplitter *splitter=new QSplitter();
	splitter->addWidget(&historyField);
	splitter->addWidget(&activeField);
	splitter->setOrientation(Qt::Vertical);
	QList<int> sizes;
	sizes.push_back(400);
	sizes.push_back(30);
	splitter->setSizes(sizes);
	splitter->setCollapsible(0,false);
	splitter->setCollapsible(1,false);
	vBoxLayout->addWidget(splitter);
	setLayout(vBoxLayout);

	historyField.setReadOnly(true);

	connect(this,SIGNAL(appendMessage(QString)),&historyField, SLOT(append(QString)));
	connect(&activeField, SIGNAL(enterPressed(QString)), this, SLOT(inputReceived(QString)));
}

void ChatWindow::inputReceived(QString input){
	messageReceived(myUsername, input);
}
void ChatWindow::messageReceived(QString username, QString message){
	QString msg=username + ":" + message ;
	emit appendMessage(msg);
}

void ChatWindow::newPartnerConnected(QString username, int connectionId){
}
void ChatWindow::partnerStateChanged(QString username, int newState){
}







