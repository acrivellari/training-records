#ifndef IO_H
#define IO_H

class IO {

};

#endif

/*
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <iomanip>

void Model::serialize(Training* t, QJsonObject & obj){
    obj["id"]=static_cast<int>(t->id);
    obj["date"]=QString::fromStdString(t.addZeroDate(t->getYear())+"-"+t->addZeroDate(t->getMonth())+"-"+t->addZeroDate(t->getDay()));
    QJsonObject data;
    for(auto cit=t->tData.cbegin(); cit!=t->tData.cend();cit++){
        std::string valueExercise = "";
        for(auto cit1=(*cit)->tSets.cbegin(); cit1!=(*cit)->tSets.cend(); cit1++){
            valueExercise=valueExercise+std::to_string(*cit1);
        }
        data[QString::fromStdString((*cit)->tName)]=QString::fromStdString(valueExercise);
    }
    obj["data"]=data;

}

void Model::load(std::string path) try
{
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
        for(QJsonArray::const_iterator cit=year_array.constBegin(); cit!=year_array.constEnd(); cit++){

            unsigned int id;std::string date;std::string pullup;std::string pushup;std::string squat;std::string jumprope;

            if(cit->isObject())     training_object=cit->toObject();
            else    throw new _exception;

            if(training_object.contains("id") && training_object.value("id").isDouble())  id=(unsigned int)training_object.value("id").toInt();
            else    throw new _exception;

            if(training_object.contains("date") && training_object.value("date").isString())  date=training_object.value("date").toString().toStdString();
            else    throw new _exception;

            if(training_object.contains("data") && training_object.value("data").isObject())    training_object_data=training_object.value("data").toObject();
            else    throw new _exception;

            QStringList keys=training_object_data.keys();
            Training* tmp = new Training(id,date);
            for(QStringList::iterator it=keys.begin();it!=keys.end();it++){
                if(training_object_data.contains(*it) && training_object_data.value(*it).isString())
                    tmp->addTraining((*it).toStdString(),training_object_data.value(*it).toString().toStdString());
            }
            push_end(tmp);
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


*/
