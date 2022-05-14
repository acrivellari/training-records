#include "../usersauth.h"
#include "../backendException.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <iostream>

UsersAuth::UsersAuth(std::string p) : pathDB{p}{}

bool UsersAuth::giveCredentials(std::string user, std::string pass) const try {
    QFile loadFile(QString::fromStdString(pathDB));
    if (!loadFile.open(QIODevice::ReadOnly)) {
        throw new BackendException("Cannot open file");
    }
    QJsonDocument doc(QJsonDocument::fromJson(loadFile.readAll()));
    loadFile.close();

    if(!doc.isArray()){
        throw new BackendException("JSON bad formed : json must start with a jsonArray");
    }
    QJsonArray arrayJ(doc.array());

    bool check = false;
    for (QJsonArray::ConstIterator cit = arrayJ.constBegin(); cit != arrayJ.constEnd(); cit++) {
        QJsonObject userJ;
        if (cit -> isObject()) {
            userJ = cit->toObject();
        }else {
            throw new BackendException("User json bad formed, should be array of objects");
        }
        if (userJ.contains("username") && userJ.contains("password")){
            if (userJ.value("username").isString() && userJ.value("password").isString()) {
                if (user == userJ.value("username").toString().QString::toStdString() &&
                        pass == userJ.value("password").toString().QString::toStdString()) {
                    check = true;
                    break;
                }
            }else {
                throw new BackendException("User json is bad formed, user and pass should be strings");
            }
        }else {
            throw new BackendException("User json is bad formed, should contain username and password attributes");
        }
    }
    return check;
} catch(BackendException* e){
    std::cout<<e->getMessage();
    return false;
}

bool UsersAuth::addCredentials(std::string user, std::string pass) {
    QFile loadFile(QString::fromStdString(pathDB));
    if (!loadFile.open(QIODevice::ReadOnly)) {
        throw new BackendException("Cannot open load file");
    }
    QJsonDocument doc(QJsonDocument::fromJson(loadFile.readAll()));
    loadFile.close();

    if(!doc.isArray()){
        throw new BackendException("JSON bad formed : json must start with a jsonArray");
    }
    QJsonArray arrayJ(doc.array());

    //check if it exists
    bool check = false;
    for (QJsonArray::ConstIterator cit = arrayJ.constBegin(); cit != arrayJ.constEnd(); cit++) {
        QJsonObject userJ;
        if (cit -> isObject()) {
            userJ = cit->toObject();
        }else {
            throw new BackendException("User json bad formed, should be array of objects");
        }
        if (userJ.contains("username") && userJ.contains("password")){
            if (userJ.value("username").isString() && userJ.value("password").isString()) {
                if (user == userJ.value("username").toString().QString::toStdString()) {
                    check = true;
                    break;
                }
            }else {
                throw new BackendException("User json is bad formed, user and pass should be strings");
            }
        }else {
            throw new BackendException("User json is bad formed, should contain username and password attributes");
        }
    }
    bool finalReturn = false;
    if (!check) {
        QJsonObject newAccount;
        newAccount["username"] = QString::fromStdString(user);
        newAccount["password"] = QString::fromStdString(pass);
        arrayJ.push_back(newAccount);

        QJsonDocument doc(arrayJ);
        QFile saveFile(QString::fromStdString(pathDB));
        if(!saveFile.open(QIODevice::WriteOnly)){
            throw new BackendException("Cannot open save file");
        }
        saveFile.write(doc.toJson());
        saveFile.close();
        finalReturn = true;
    }
    std::cout<<"nice";
    return finalReturn;

}

