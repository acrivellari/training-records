#include "../jsonio.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

JsonIO::JsonIO(std::string filePath) : path{filePath} {}

void JsonIO::load(Model* m, std::string p) const {
    m -> clear();
    QFile loadFile;
    if (p.empty()){
        loadFile.setFileName(QString::fromStdString(path));
    }else {
        loadFile.setFileName(QString::fromStdString(p));
    }
    if (!loadFile.open(QIODevice::ReadOnly)) {
        throw new BackendException("Cannot open file");
    }
    QJsonDocument doc(QJsonDocument::fromJson(loadFile.readAll()));
    loadFile.close();

    if(!doc.isObject()){
        throw new BackendException("JSON bad formed : json must start with a jsonObject");
    }

    QJsonObject object(doc.object());
    for (QJsonObject::ConstIterator cit0 = object.constBegin(); cit0 != object.constEnd(); cit0++) {
        QJsonArray year_array;
        if (cit0 -> isArray()) {
            year_array = cit0 -> toArray();
        }else {
            throw new BackendException("JSON bad formed: in the second level there must be a list of jsonArrays");
        }
        for (QJsonArray::ConstIterator cit = year_array.constBegin(); cit != year_array.constEnd(); cit++) {
            QJsonObject trainingObject;
            if (cit -> isObject()) {
                trainingObject = cit -> toObject();
            }else {
                throw new BackendException("JSON bad formed: in the third level there must be jsonObjects (array of them)");
            }

            if (trainingObject.contains("id")) {
                if (!(trainingObject.value("id").isDouble())) {
                    throw new BackendException("JSON bad formed: the id should be in number format");
                }
            }else {
                throw new BackendException("JSON bad formed: there must be an id attribute");
            }

            QString date;
            if (trainingObject.contains("date")) {
                if (trainingObject.value("date").isString()) {
                    date = trainingObject.value("date").toString();
                }else {
                    throw new BackendException("JSON bad formed: the date should be in string format");
                }
            }else {
                throw new BackendException("JSON bad formed: there must be a date attribute");
            }

            QJsonObject trainingData;
            if (trainingObject.contains("data")) {
                if (trainingObject.value("data").isObject()) {
                    trainingData = trainingObject.value("data").toObject();
                }else {
                    throw new BackendException("JSON bad formed: in the fourth level there must be a jsonObject");
                }
            }else {
                throw new BackendException("JSON bad formed: there must be a data attribute");
            }

            //Load all exercises of this training
            unsigned int index = m ->addEmptyTraining(date.QString::toStdString());
            for(QString key : trainingData.keys()) {
                std::vector<std::string> exerciseV{key.QString::toStdString(), trainingData.value(key).toString().QString::toStdString()};
                m -> addExerciseTraining(index, exerciseV);
            }
        }
    }
} /*catch (BackendException* e) {
    throw e;
}*/

bool JsonIO::save(Model* m, std::string p) const {

    QFile saveFile;
    if (p.empty()){
        saveFile.setFileName(QString::fromStdString(path));
    }else {
        saveFile.setFileName(QString::fromStdString(p));
    }
    if(!saveFile.open(QIODevice::WriteOnly)){
        return false;
    }

    QJsonObject object_root;

    for (std::string& actualYear : m -> getYears()){
        QJsonArray arrayJ;
        for (unsigned int i = 0; i < m->getSize(); i++) {
            Training* t = m -> at (i);
            if (t -> getDate("year") == actualYear) {
                QJsonObject trainingObject;
                trainingObject["id"] = (int) t -> getID();
                trainingObject["date"] = QString::fromStdString(t -> getDate("all"));
                QJsonObject trainingData;
                trainingObject["data"] = trainingData;
                for (unsigned int j = 0; j < t -> getNExercises(); j++) {
                    trainingData[QString::fromStdString(t -> getExercise(j)[0])] = QString::fromStdString(t -> getExercise(j)[1]);
                    std::cout<<(t -> getExercise(j)[1]);
                }


                arrayJ.push_back(trainingObject);
            }

        }
        object_root.insert(QString::fromStdString(actualYear), arrayJ);
    }
    QJsonDocument doc(object_root);
    saveFile.write(doc.toJson());
    saveFile.close();
    return true;
}
