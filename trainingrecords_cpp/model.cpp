#include "model.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>

void Model::push_end(Training * t)
{
    list.push_back(t);
}

void Model::load(std::string path) try
{
    //da completare
    QFile loadFile(QString::fromStdString(path));
    if(!loadFile.open(QIODevice::ReadOnly)){
        throw new _exception;
    }
    QByteArray savedata=loadFile.readAll();
    loadFile.close();
    QJsonDocument doc(QJsonDocument::fromJson(savedata));
    if(!doc.isObject())  throw new _exception;
    QJsonObject object(doc.object());
    for(QJsonObject::const_iterator cit=object.begin(); cit!=object.end(); cit++){
        QString key=cit.key();
        QJsonArray year_array;
        QJsonObject training_object;
        QJsonObject training_object_data;
        if(key=="2020" || key=="2021"){
            if(cit->isArray())   year_array=cit->toArray();
            else    throw new _exception;
            for(QJsonArray::const_iterator cit=year_array.begin(); cit!=year_array.end(); cit++){

                unsigned int id;std::string date;std::string pullup;std::string pushup;std::string squat;std::string jumprope;

                if(cit->isObject())     training_object=cit->toObject();
                else    throw new _exception;
                if(training_object.contains("id")){
                    if(training_object.value("id").isDouble())  id=(unsigned int)training_object.value("id").toInt();
                    else    throw new _exception;
                }
                if(training_object.contains("date")){
                    if(training_object.value("date").isString())  date=training_object.value("date").toString().toStdString();
                    else    throw new _exception;
                }
                if(training_object.contains("data")){
                    if(training_object.value("data").isObject())    training_object_data=training_object.value("data").toObject();
                    else    throw new _exception;
                }
                if(training_object_data.contains("pullup")){
                    if(training_object_data.value("pullup").isString())  pullup=training_object_data.value("pullup").toString().toStdString();
                    else    pullup="";
                }
                if(training_object_data.contains("pushup")){
                    if(training_object_data.value("pushup").isString())  pushup=training_object_data.value("pushup").toString().toStdString();
                    else    pushup="";
                }
                if(training_object_data.contains("squat")){
                    if(training_object_data.value("squat").isString())  squat=training_object_data.value("squat").toString().toStdString();
                    else    squat="";
                }
                if(training_object_data.contains("jumprope")){
                    if(training_object_data.value("jumprope").isString())  jumprope=training_object_data.value("jumprope").toString().toStdString();
                    else    jumprope="";
                }
                push_end(new Training(id,date,pullup,pushup,squat,jumprope));

            }

        }
        else{
            throw new _exception;
        }
    }
}catch(_exception){
    std::cout<<"Json not well formed"<<std::endl;
}
