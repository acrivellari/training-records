#include "../jsonio.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>

JsonIO::JsonIO(std::string filePath) : path{filePath} {}

bool JsonIO::load() const
{
return true;
}

bool JsonIO::save(std::vector<std::tuple<unsigned int, std::string, std::vector<std::tuple<std::string, std::string, bool>>>>& trainingRecords, std::vector<std::string>& years)
{

    QFile saveFile(QString::fromStdString(path));
    if(!saveFile.open(QIODevice::WriteOnly)){
        //throw new BackendException("Cannot open file json.");
    }
    QJsonObject object_root;
/*

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

    for (std::string& year : years) {
        QJsonArray array;
        for (std::tuple<std::string, std::string, bool> training : trainingRecords) {
            if()
        }
    }*/

    QJsonDocument doc(object_root);
    saveFile.write(doc.toJson());
    saveFile.close();
    return true;
}
