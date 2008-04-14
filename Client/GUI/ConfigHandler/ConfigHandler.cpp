#include "ConfigHandler.h"

ConfigHandler::ConfigHandler(const QString &new_fileName){
	fileName=new_fileName;
	QFile input(fileName);
	if(!input.open(QIODevice::ReadOnly|QIODevice::Text)){
		qDebug()<<"Config file is missing:"<<fileName;
	}
	QTextStream in(&input);
	while(!in.atEnd()){
		QString line=in.readLine();
		db[line.section("=",0,0)]=line.section("=",1);
	}

	input.close();

}
QString ConfigHandler::getField(const QString &fieldName){
	return db.value(fieldName);
}
void ConfigHandler::setField(const QString &fieldName,const QString &newValue){
	db[fieldName]=newValue;
}

void ConfigHandler::save(){
	QFile output(fileName);
	if(!output.open(QIODevice::WriteOnly|QIODevice::Text)){
		qWarning()<<"Problem with opening file for writing:"<<fileName;
		return;
	}

	QHashIterator<QString, QString> i(db);
	QTextStream out(&output);
	while (i.hasNext()) {
		i.next();
		out<<i.key()<<"="<<i.value()<<endl;
	}

	output.close();
}
