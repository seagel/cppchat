#ifndef CONFIG_HANDLER
#define CONFIG_HANDLER
#include <QFile>
#include <QTextStream>
#include <QHash>
#include <QtDebug>


//c�l: a config f�jl(ok) kezel�se

class ConfigHandler{
	public:
		ConfigHandler(const QString &new_fileName);
		QString getField(const QString &fieldName);
			//az adott kulcshoz tartoz� cuccost adja vissza
		void setField(const QString &fieldName, const QString &newValue);

		void save();

	private:

		QString fileName;
		QHash<QString,QString> db;

};

#endif
