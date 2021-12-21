#include "training.h"
#include <iomanip>
Training::Training(unsigned int i, std::string d): id(i), date(d){}

Training::Training(unsigned int i, std::string d, std::map<std::string, std::string> inf): id(i),date(d){
    for(auto it=inf.begin(); it!=inf.end();it++){
        addTraining(it->first,it->second);
    }
}

void Training::addTraining(std::string type, std::string value){
    info[type]=value;
}

bool Training::modify(std::string category, std::string value){
    for(std::map<std::string, std::string>::iterator it = info.begin(); it != info.end(); it++)
        if(it->first == category){
            it->second = value;
            return true;
        }
    return false;
}

void Training::print() const{
    std::cout << "|"<< std::left << std::setw(3) << std::setfill(' ') <<id << "|";
    std::cout << std::left << std::setw(11) << std::setfill(' ') << date<< "|";
    for(auto it=info.begin(); it!=info.end();it++){
        std::cout << std::left << std::setw(19) << std::setfill(' ') << it->second<< "|";
    }
    std::cout<<std::endl;
}

std::map<std::string, std::string>  Training::printTraining() const{
    std::map<std::string, std::string> print;
    print["id"]=std::to_string(id);
    print["date"]=date;
    for(std::map<std::string, std::string>::const_iterator cit = info.begin(); cit != info.end(); cit++){
        print[cit->first]=cit->second;
    }
    return print;
}

unsigned int Training::getID() const{
    return id;
}

std::string Training::getYear() const{
    std::string year;
    for(unsigned int i=0; i<4; i++)
        year.append(1,date[i]);
    return year;

}

std::string Training::getMonth() const{
    std::string month;
    for(unsigned int i=0; i<7; i++)
        month.append(1,date[i]);
    return month;
}

void Training::serialize(QJsonObject & obj){
    obj["id"]=static_cast<int>(id);
    obj["date"]=QString::fromStdString(date);
    QJsonObject data;
    for(auto it=info.begin(); it!=info.end();it++){
        data[QString::fromStdString(it->first)]=QString::fromStdString(it->second);
    }
    obj["data"]=data;

}

