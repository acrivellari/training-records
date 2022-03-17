#include "training.h"
#include <iomanip>

Training::TrainingDate::TrainingDate(int y, int m, int d) : year(y), month(m), day(d){}
Training::TrainingDate::TrainingDate(std::string date){
    std::vector<int> vecDate = string2date(date);
    year=vecDate[0];month=vecDate[1];day=vecDate[3];
}
Training::TrainingExercise::TrainingExercise(std::string name, std::vector<unsigned int> sets, bool type): tName(name), tType(type), tSets(sets){}
Training::Training(unsigned int i, std::string d): id(i), tDate(TrainingDate(d)){}

Training::~Training(){
    for(auto it=tData.begin(); it!=tData.end(); it++)   delete *it;
}

void Training::addExerciseData(std::string name, std::string value, bool type){
    tData.push_back(new TrainingExercise(name, string2sets(value,type), type));
}
void Training::removeExercise(std::string name){
    for(auto it=tData.begin(); it!=tData.end(); it++){
        if(((*it)->tName)==name) delete *it;
    }
}
void Training::modifyTrainingDate(std::string date){
    std::vector<int> vecDate = string2date(date);
    setYear(vecDate[0]);setMonth(vecDate[1]);setDay(vecDate[2]);
}

void Training::print() const{
    std::cout << "|"<< std::left << std::setw(3) << std::setfill(' ') <<id << "|";
    std::cout << std::left << std::setw(3) << std::setfill(' ') <<addZeroDate(tDate.day)<<"/"<<addZeroDate(tDate.month)<<"/"<<tDate.year << "|";
    for(auto cit=tData.cbegin(); cit!=tData.cend();cit++){
        for(auto it=((*cit)->tSets).begin();it!=((*cit)->tSets).end();it++){
            std::cout << std::left << std::setw(19) << std::setfill(' ') << *it << "|";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

std::vector<std::vector<std::string>>  Training::printTraining() const{
    std::vector<std::vector<std::string>> print;

    std::vector<std::string> printId;
    printId.push_back("ID: ");
    printId.push_back(std::to_string(id));
    print.push_back(printId);

    std::vector<std::string> date;
    date.push_back("Date: ");
    date.push_back(addZeroDate(getDay())+"/"+addZeroDate(getMonth())+"/"+addZeroDate(getYear()));
    print.push_back(date);

    for(auto cit=tData.cbegin(); cit!=tData.cend(); cit++){
        std::vector<std::string> actualExercise;
        actualExercise.push_back((*cit)->tName);
        actualExercise.push_back(type2string((*cit)->tType));
        for(auto cit1=(*cit)->tSets.cbegin(); cit1!=(*cit)->tSets.cend();cit1++)
            actualExercise.push_back(std::to_string(*cit1));
        print.push_back(actualExercise);
    }

    return print;
}


std::vector<unsigned int> Training::string2sets(std::string value, bool type){
    std::vector<unsigned int> sets;
        std::string tmp = "";
        for(unsigned int i=0; i<value.length();i++){
            if(isdigit(value[i])){
                tmp=tmp+value[i];
            }else{
                if(value[i]=='\'' && !type)   throw _exception();
                if(value[i]=='-'){
                    sets.push_back(std::stoul(tmp));
                    tmp="";
                }
            }
        }
        if(tmp!="") sets.push_back(std::stoul(tmp));
        return sets;
}

std::vector<int> Training::string2date(std::string date){
    std::vector<int> vecDate;
    std::string tmp = "";
    for(unsigned int i=0; i<date.length(); i++){
        if(isdigit(date[i])){
            tmp=tmp+date[i];
        }else{
            if(date[i]=='-'){
                vecDate.push_back(std::stoi(tmp));
                tmp="";
            }
        }
    }
    vecDate.push_back(std::stoi(tmp));
    return vecDate;
}

std::string Training::addZeroDate(int i){
    if((i/10)<1)    return "0"+std::to_string(i);
}

std::string Training::type2string(bool type){
    if(type)    return "Repetitions";
    else    return "Seconds";
}

//methods getters and setters for tDate
unsigned int Training::getYear() const{
    return tDate.year;}
unsigned int Training::getMonth() const{
    return tDate.month;}
unsigned int Training::getDay() const{
    return tDate.day;}
void Training::setYear(int i){
    tDate.year=i;}
void Training::setMonth(int i){
    tDate.month=i;}
void Training::setDay(int i){
    tDate.day=i;}
