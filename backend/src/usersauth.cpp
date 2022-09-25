#include "../usersauth.h"
#include "../backendException.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <iostream>


UsersAuth::UsersAuth(std::string p) : pathDB{p}{}

bool UsersAuth::giveCredentials(std::string user, std::string pass) try {
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
                    password = pass;
                    username = user;
                    if (userJ.contains("name") && userJ.value("name").isString())
                        name = userJ.value("name").toString().QString::toStdString();
                    else    name = "";
                    if (userJ.contains("surname") && userJ.value("surname").isString())
                        surname = userJ.value("surname").toString().QString::toStdString();
                    else    surname = "";
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

bool UsersAuth::addCredentials(std::string user, std::string pass, std::string namee, std::string surnamee) try{
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

    //check if the user already exists
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
        newAccount["name"] = QString::fromStdString(namee);
        newAccount["surname"] = QString::fromStdString(surnamee);
        arrayJ.push_back(newAccount);

        QJsonDocument doc(arrayJ);
        QFile saveFile(QString::fromStdString(pathDB));
        if(!saveFile.open(QIODevice::WriteOnly)){
            throw new BackendException("Cannot open save file");
        }
        saveFile.write(doc.toJson());
        saveFile.close();
        finalReturn = true;
        password = pass;
        username = user;
        name = namee;
        surname = surnamee;
    }
    return finalReturn;
} catch(BackendException* e){
    std::cout<<e->getMessage();
    return false;
}

bool UsersAuth::changeCredentials(std::string user, std::string olduser, std::string pass, std::string namee, std::string surnamee) try{
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

    //check if the new username already exists
    bool check = false;
    for (QJsonArray::ConstIterator cit = arrayJ.constBegin(); cit != arrayJ.constEnd(); cit++) {
        if (cit -> isObject() && cit->toObject().contains("username") && cit->toObject().contains("password")){
            QJsonObject userJ = cit->toObject();
            if (userJ.value("username").isString() && userJ.value("password").isString()) {
                if (user == userJ.value("username").toString().QString::toStdString()) {
                    check = true;
                    break;
                }
            }
        }
    }

    bool finalReturn = false;
    if (user == olduser)    check = false;
    if (!check) {
        for (QJsonArray::Iterator cit = arrayJ.begin(); cit != arrayJ.end(); cit++) {
            if (cit -> isObject() && cit -> toObject().contains("username") && cit -> toObject().value("username").toString().QString::toStdString() == olduser) {
                arrayJ.erase(cit);
                QJsonObject newOne;
                newOne["username"] = QString::fromStdString(user);
                newOne["password"] = QString::fromStdString(pass);
                newOne["name"] = QString::fromStdString(namee);
                newOne["surname"] = QString::fromStdString(surnamee);
                username = user;
                password = pass;
                name = namee;
                surname = surnamee;

                arrayJ.push_back(newOne);
                QJsonDocument doc1(arrayJ);
                QFile saveFile(QString::fromStdString(pathDB));
                if(!saveFile.open(QIODevice::WriteOnly)){
                    throw new BackendException("Cannot open save file");
                }
                saveFile.write(doc1.toJson());
                saveFile.close();
                finalReturn = true;
            }
        }
    }
    
    return finalReturn;
} catch(BackendException* e){
    std::cout<<e->getMessage();
    return false;
}

std::string UsersAuth::getCredential(std::string type) const {
    if (type == "name") 
        return name;
    else if (type == "surname")
        return surname;
    else if (type == "username") 
        return username;
    else if (type == "password") 
        return password;
    else    throw new BackendException("Wrong parameter given");
}