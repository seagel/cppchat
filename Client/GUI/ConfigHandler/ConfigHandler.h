#ifndef CONFIG_HANDLER
#define CONFIG_HANDLER
#include <QFile>
#include <QTextStream>
#include <QHash>
#include <QtDebug>


//cél: a config fájl(ok) kezelése

class ConfigHandler{
	public:
		ConfigHandler(const QString &new_fileName);
		QString getField(const QString &fieldName);
			//az adott kulcshoz tartozó cuccost adja vissza
		void setField(const QString &fieldName, const QString &newValue);

		void save();

	private:

		QString fileName;
		QHash<QString,QString> db;

};

#endif
