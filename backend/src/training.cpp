#include "../training.h"
#include <iomanip>
#include "backendException.cpp"


//public methods
void Training::addTrainingExercise(std::string name, std::string value) {
    bool type = getType(value);
    tData.push_back(new TrainingExercise(name, string2sets(value, type), type));
}

void Training::addTrainingExercise(std::string name, std::string value, bool type) {
    tData.push_back(new TrainingExercise(name, string2sets(value, type), type));
}

void Training::addTrainingExercise(std::string name, std::string value, std::string type) {
    tData.push_back(new TrainingExercise(name, string2sets(value, TrainingExercise::getType(type)), type));
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

bool Training::operator< (const Training& T) const {
    if (getYear() < T.getYear()) return true;
    else if (getYear() > T.getYear())   return false;
    else if (getMonth() < T.getMonth()) return true;
    else if (getMonth() > T.getMonth()) return false;
    else if (getDay() < T.getDay()) return true;
    else if (getDay() > T.getDay()) return false;
    else if (getID() < T.getID())   return true;
    else    return false;

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

std::string Training::getDate(std::string how) const {
    if (how == "day") {
        return stringDate(getDay());
    } else if (how == "month") {
        return stringDate(getMonth());
    } else if (how == "year") {
        return stringDate(getYear());
    } else if (how == "all") {
        return stringDate(getYear()) + "-" + stringDate(getMonth()) + "-" + stringDate(getDay());
    } else  throw new BackendException("Type of date requested is wrong.");

}

unsigned int Training::getNExercises() const {
    return tData.size();
}

std::vector<std::string> Training::getExercise(unsigned int idEx) const {
    TrainingExercise* tmp = tData[idEx];
    return tmp->getExercise();
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


//private methods

Training::TrainingDate::TrainingDate(int y, int m, int d) : year(y), month(m), day(d) {}

Training::TrainingDate::TrainingDate(std::string date) {
    std::vector<int> vecDate = string2dateInt(date);
    year = vecDate.at(0);
    month = vecDate.at(1);
    day = vecDate.at(2);
}

Training::TrainingExercise::TrainingExercise(std::string name, std::vector<unsigned int> sets, bool type): tName(name), tType(type), tSets(sets) {}

Training::TrainingExercise::TrainingExercise(std::string name, std::vector<unsigned int> sets, std::string type): tName(name), tType(false), tSets(sets) {
    if (type == "reps") tType = false;
    else if (type == "seconds") tType = true;
    else    throw new BackendException("The type of the training exercise isn't valid.");
}

Training::Training(unsigned int i, std::string d): id{i}, tDate{TrainingDate(d)} {}

Training::~Training() {
    for (TrainingExercise* tEx : tData)   delete tEx;
}

bool Training::TrainingExercise::getType(std::string type) {
    if (type == "seconds")  return true;
    else if (type == "reps")    return false;
    else    throw new BackendException("This type does not exist.");
}

std::string Training::TrainingExercise::getType(bool type) {
    if (type)   return "seconds";
    else    return "reps";
}

std::string Training::TrainingExercise::getSets() const {
    std::string result{};
    for (const unsigned int repS : tSets) {
        result += std::to_string(repS);
        if (tType)  result.push_back('"');
        result.push_back('-');
    }
    if (tType)  result.pop_back();
    result.pop_back();
    return result;
}

std::vector<std::string> Training::TrainingExercise::getExercise() const {
    std::vector<std::string> result{};
    result.push_back(tName);
    result.push_back(getSets());
    result.push_back(getType(tType));
    return result;
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
                        if (repS == '"' && tEx -> tType == false)    throw new BackendException("Input data, bad created.\nThere can't be \" in non-sec sets");
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
    setYear(vecDate.at(0));
    setMonth(vecDate.at(1));
    setDay(vecDate.at(2));
    return true;
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

bool Training::getType(std::string sets) {
    bool sec{false};
    for (char repS : sets) {
        if (repS == '\"')   sec = true;
    }
    return sec;
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

