#include "DatabaseService.h"

#include <QXmlStreamReader>
#include <QFile>
#include <QMap>
#include <stdexcept>

Models::DatabaseService::DatabaseService()
{
    QMap<QString, QString> params;
    QStringList expected_params = {"driver", "hostname", "port", "DBname", "username", "password", "schema"};
    QString filename = "db_config.xml";
    QString dir_path = "C:\\Users\\crive\\Desktop\\training-records\\Database\\";

    try
    {
        readConfigFile(dir_path + filename, &expected_params, &params);
    }
    catch(const std::runtime_error& e)
    {
        qWarning() << "Run time exception: " << e.what();
    }

    conn = QSqlDatabase::addDatabase(params["driver"]);
    conn.setHostName(params["hostname"]);
    conn.setPort(params["port"].toInt());
    conn.setDatabaseName(params["DBname"]);
    conn.setUserName(params["username"]);
    conn.setPassword(params["password"]);

    schema = params["schema"];

    if (! conn.open())
    {
        throw std::runtime_error("DB error: couldn't connect with database. Control the db_config file.");
    }
}

Models::Resources::User* Models::DatabaseService::getUserByUsername(const QString & username)
{
    return Models::DAOs::UserDAO::getUserByUsername(username, &conn, schema);
}

bool Models::DatabaseService::insertNewUser(Resources::User* user)
{
    return Models::DAOs::UserDAO::insertNewUser(user, &conn, schema);
}


void Models::DatabaseService::readConfigFile(const QString& filename, QStringList* expected_params, QMap<QString, QString>* params) const noexcept(false)
{
    QFile file(filename);


    if (! file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Failed to open file:" << filename;
        throw std::runtime_error("Failed to open file: " + filename.toStdString());
    }

    QXmlStreamReader xmlReader(&file);


    while (!xmlReader.atEnd() && !xmlReader.hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader.readNext();

        if (token == QXmlStreamReader::StartElement && xmlReader.name().toString() == "DbConfig")
        {
            for(const QString& attr : *expected_params)
            {
                if (! xmlReader.attributes().hasAttribute(attr))
                {
                    throw std::runtime_error("XML Error: config file doesn't have a compulsory attribute (" + attr.toStdString() + ")");
                }
                params -> insert(
                    attr,
                    xmlReader.attributes().value(attr).toString());
            }
        }
    }
    if (xmlReader.hasError())
    {
        throw std::runtime_error("XML Error: " + xmlReader.errorString().toStdString());
    }


    file.close();
}
