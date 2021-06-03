#include "training.h"
#include <iomanip>
Training::Training(unsigned int i, std::string d): id(i), date(d){}

Training::Training(unsigned int i, std::string d, std::map<std::string, std::string> inf): id(i),date(d)
{
    for(auto it=inf.begin(); it!=inf.end();it++){
        addTraining(it->first,it->second);
    }
}

void Training::addTraining(std::string type, std::string value)
{
    info[type]=value;
}

void Training::print() const
{
    std::cout << "|"<< std::left << std::setw(3) << std::setfill(' ') <<id << "|";
    std::cout << std::left << std::setw(11) << std::setfill(' ') << date<< "|";
    for(auto it=info.begin(); it!=info.end();it++){
        std::cout << std::left << std::setw(19) << std::setfill(' ') << it->second<< "|";
    }
    std::cout<<std::endl;
}

unsigned int Training::getID() const
{
    return id;
}

std::string Training::getYear() const
{
    std::string year;
    year.append(1,date[0]);year.append(1,date[1]);year.append(1,date[2]);year.append(1,date[3]);
    return year;

}

std::string Training::getMonth() const
{
    std::string month;
    month.append(1,date[0]);month.append(1,date[1]);month.append(1,date[2]);month.append(1,date[3]);month.append(1,date[4]);month.append(1,date[5]);month.append(1,date[6]);
    return month;
}

void Training::serialize(QJsonObject & obj)
{
    obj["id"]=static_cast<int>(id);
    obj["date"]=QString::fromStdString(date);
    QJsonObject data;
    for(auto it=info.begin(); it!=info.end();it++){
        data[QString::fromStdString(it->first)]=QString::fromStdString(it->second);
    }
    obj["data"]=data;

}

