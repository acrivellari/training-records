#include "model.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <iomanip>


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


void Model::add(std::string date, std::map<std::string,std::string> info){
    push_end(new Training(getHighestID()+1,date,info));
}

bool Model::remove(unsigned int toRemove){
    for(std::vector<Training*>::iterator it = list.begin(); it!=list.end(); it++){
        if((*it)->getID()==toRemove){
            list.erase(it);
            return true;
        }
    }
    return false;
}

bool Model::modify(unsigned int toModify, std::string category, std::string value){
    for(std::vector<Training*>::iterator it = list.begin(); it != list.end(); it++)
        if((*it)->getID()==toModify)
            return ((*it)->modify(category, value));
    return false;
}

std::map<std::string, std::string> Model::printTraining(unsigned int i) const{
    std::map<std::string, std::string> result;
    for(std::vector<Training*>::const_iterator cit = list.begin(); cit != list.end(); cit++)
        if((*cit)->getID()==i)
            return (*cit)->printTraining();
    return result;
}

void Model::print_all() const
{
    std::cout<<"Print all TRAININGS:\n";
    std::cout << std::left << std::setw(4) << std::setfill(' ') << "|Id";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << "|Date";
    std::cout << std::left << std::setw(20) << std::setfill(' ') << "|Jump Rope";
    std::cout << std::left << std::setw(20) << std::setfill(' ') << "|Pullup";
    std::cout << std::left << std::setw(20) << std::setfill(' ') << "|Pushup";
    std::cout << std::left << std::setw(5) << std::setfill(' ') << "|Squat\n";
    for(unsigned int i=0; i<list.size(); i++)  list[i]->print();
}

void Model::print(unsigned int toPrint){
    for(std::vector<Training*>::iterator it = list.begin(); it != list.end(); it++)
        if((*it)->getID()==toPrint)
            (*it)->print();
}

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
