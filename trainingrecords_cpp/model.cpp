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

bool Model::isEmpty() const
{
    if(list.size())    return true;
    else    return false;
}

unsigned int Model::getHighestID() const
{
    unsigned int result=0;
    for(unsigned int i=0; i<list.size(); i++)  if(list[i]->getID()>result)   result=list[i]->getID();
    return result;
}

std::vector<std::string> Model::getYears() const
{
    std::vector<std::string> years;
    for(unsigned int i=0; i<list.size(); i++){
        if(years.size()==0) years.push_back(list[i]->getYear());
        else{
            bool counter=true;
            for(unsigned int j=0; j<years.size(); j++){
                if(years[j]==list[i]->getYear())    counter=false;
            }
            if(counter) years.push_back(list[i]->getYear());
        }

    }
    return years;
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
        QJsonArray year_array;
        QJsonObject training_object;
        QJsonObject training_object_data;
        if(cit->isArray())   year_array=cit->toArray();
        else    throw new _exception;
        for(QJsonArray::const_iterator cit=year_array.cbegin(); cit!=year_array.cend(); cit++){

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
}catch(_exception){
    std::cout<<"Json not well formed"<<std::endl;
}

void Model::save(std::string path) const
{
    QFile saveFile(QString::fromStdString(path));
    if(!saveFile.open(QIODevice::WriteOnly)){
        throw new _exception;
    }
    QJsonObject object_root;

    std::vector<std::string> years = getYears();

    for(unsigned int i=0; i<years.size(); i++){
        QJsonArray array;
        for(unsigned j=0; j<list.size(); j++){

            if(list[j]->getYear()==years[i]){

                QJsonObject training_obj;
                list[j]->serialize(training_obj);
                array.push_back(training_obj);


            }
        }
        object_root.insert(QString::fromStdString(years[i]),array);
    }

    QJsonDocument doc(object_root);
    saveFile.write(doc.toJson());
    saveFile.close();
}


void Model::add(std::string date, std::string pullup, std::string pushup, std::string squat, std::string jumprope){
    push_end(new Training(getHighestID()+1,date,pullup,pushup,squat,jumprope));
    std::string year;
    year.append(1,date[0]);year.append(1,date[1]);year.append(1,date[2]);year.append(1,date[3]);
}




void Model::print_all() const
{
    for(unsigned int i=0; i<list.size(); i++)  list[i]->print();
}
