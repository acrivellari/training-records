#include "../training.h"
#include <iomanip>
#include "backendException.cpp"

Training::TrainingDate::TrainingDate(int y, int m, int d) : year(y), month(m), day(d) {}

Training::TrainingDate::TrainingDate(std::string date) {
    std::vector<int> vecDate = string2dateInt(date);
    year = vecDate[0];
    month = vecDate[1];
    day = vecDate[2];
}

Training::TrainingExercise::TrainingExercise(std::string name, std::vector<unsigned int> sets, bool type): tName(name), tType(type), tSets(sets) {}

Training::Training(unsigned int i, std::string d): id{i}, tDate{TrainingDate(d)} {}

Training::~Training() {
    for (TrainingExercise* tEx : tData)   delete tEx;
}



void Training::addTrainingExercise(std::string name, std::string value, bool type) {
    tData.push_back(new TrainingExercise(name, string2sets(value, type), type));
}

Training* Training::addEmptyTraining(unsigned int i, std::string d) {
    return new Training(i,d);
}

void Training::removeExercise(std::string name) {
    for (TrainingExercise* tEx : tData){
        if (tEx -> tName == name) delete tEx;
    }
}

bool Training::modify(std::string category, std::string value) {
    if (category == "date") {
        return modifyTrainingDate(value);
    } else if (category.find("exercise:") != std::string::npos) {
        return modifyTrainingExercise(category, value);
    } else  return false;
}

bool Training::modifyTrainingExercise(std::string category, std::string value) try {

    if(category.find("exercise:name:") != std::string::npos) {
        //name
        std::string nameToModify{};
        unsigned int count{0};
        for (char c : category) {
            if (count == 2) nameToModify.push_back(c);
            if (c == ':')   count++;
        }
        for (TrainingExercise* tEx : tData) {
            if (tEx -> tName == nameToModify){
                tEx -> tName = value;
                return true;
            }
        }
    } else if(category.find("exercise:data:") != std::string::npos) {
        //data
        std::string dataToModify{};
        unsigned int count{0};
        for (char c : category) {
            if (count == 2) dataToModify.push_back(c);
            if (c == ':')   count++;
        }
        for (TrainingExercise* tEx : tData) {
            if (tEx -> tName == dataToModify){
                std::vector<unsigned int> newSets{};
                std::string tmp{};
                for (char repS : value) {
                    if (isdigit(repS))  tmp += repS;
                    else{
                        if (repS == '\"' && tEx -> tType == false)    throw new BackendException("Input data, bad created.\nThere can't be \" in non-sec sets");
                        if (repS == '-') {
                            newSets.push_back(std::stoul(tmp));
                            tmp = "";
                        }
                    }
                }
                if(tmp != "") newSets.push_back(std::stoul(tmp));
                tEx -> tSets = newSets;
                return true;
            }
        }
    }
    return false;
}
catch(BackendException* e) {
    std::cout<<e->what();
    return false;
}

bool Training::modifyTrainingDate(std::string date) {
    std::vector<int> vecDate = string2dateInt(date);
    setYear(vecDate[0]);
    setMonth(vecDate[1]);
    setDay(vecDate[2]);
    return true;
}

void Training::print() const {
    std::cout << "|"<< std::left << std::setw(3) << std::setfill(' ') <<id << "|";
    std::cout << std::left << std::setw(3) << std::setfill(' ') << stringDate(tDate.day) << "/" << stringDate(tDate.month) << "/" << stringDate(tDate.year) << "|";
    for (const TrainingExercise* tEx : tData) {
        for (const unsigned int repS : tEx -> tSets) {
            std::cout << std::left << std::setw(19) << std::setfill(' ') << repS << "|";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

std::vector<std::vector<std::string>>  Training::printTraining() const {
    std::vector<std::vector<std::string>> print{};

    std::vector<std::string> printId{};
    printId.push_back("ID: ");
    printId.push_back(std::to_string(id));
    print.push_back(printId);

    std::vector<std::string> date{};
    date.push_back("Date: ");
    date.push_back(stringDate(getDay()) + "/" + stringDate(getMonth()) + "/" + stringDate(getYear()));
    print.push_back(date);

    for (const TrainingExercise* tEx : tData) {
        std::vector<std::string> actualExercise{};
        actualExercise.push_back(tEx -> tName);
        actualExercise.push_back(type2string(tEx -> tType));
        for (const unsigned int repS : tEx -> tSets) {
            actualExercise.push_back(std::to_string(repS));
        }
        print.push_back(actualExercise);
    }
    return print;
}

void Training::getTraining(unsigned int& id, std::string& date, std::vector<std::tuple<std::string, std::string, bool>>& trainingData) {
    id = getID();
    date = stringDate(getYear()) + "-" + stringDate(getMonth()) + "-" + stringDate(getDay());
    //"yyyy-mm-dd"

    for (TrainingExercise* tEx : tData) {
        std::string setsActualEx{};
        for (unsigned int repS : tEx->tSets) {
            setsActualEx += std::to_string(repS);
            if (tEx->tType == true) setsActualEx += '"';
            setsActualEx += '-';
        }
        std::tuple<std::string, std::string, bool> actualEx = std::make_tuple(tEx->tName,setsActualEx, tEx->tType);
        trainingData.push_back(actualEx);
    }
}

std::vector<unsigned int> Training::string2sets(std::string value, bool type) try {
    std::vector<unsigned int> sets{};
    std::string tmp{};
    for (char repS : value) {
        if (isdigit(repS))  tmp += repS;
        else{
            if (repS == '\"' && type == false)    throw new BackendException("Input data, bad created.\nThere can't be \" in non-sec sets");
            if (repS == '-') {
                sets.push_back(std::stoul(tmp));
                tmp = "";
            }
        }
    }
    if(tmp != "") sets.push_back(std::stoul(tmp));
    return sets;
}
catch(BackendException* e){
    std::cout<<e->what();
    std::vector<unsigned int> tmp{};
    return tmp;
}

std::vector<int> Training::string2dateInt(std::string date) {
    std::vector<int> vecDate{};
    std::string tmp{};
    for (char cDate : date) {
        if (isdigit(cDate)) {
            tmp = tmp + cDate;
        } else {
            if (cDate == '-') {
                vecDate.push_back(std::stoi(tmp));
                tmp = "";
            }
        }
    }
    vecDate.push_back(std::stoi(tmp));
    return vecDate;
}


std::string Training::stringDate(int i) {
    if ((i / 10) < 1)    return "0" + std::to_string(i);
    return std::to_string(i);
}

std::string Training::type2string(bool type) {
    if (type == true)    return "Repetitions";
    else    return "Seconds";
}

//methods getters and setters for tDate

unsigned int Training::getID() const {
    return id;
}

unsigned int Training::getYear() const {
    return tDate.year;
}

unsigned int Training::getMonth() const {
    return tDate.month;
}

unsigned int Training::getDay() const {
    return tDate.day;
}

void Training::setYear(int i) {
    tDate.year = i;
}

void Training::setMonth(int i) {
    tDate.month = i;
}

void Training::setDay(int i) {
    tDate.day = i;
}

