#include "training.h"
#include <iomanip>
Training::Training(unsigned int i, std::string s, std::string d1, std::string d2, std::string d3, std::string d4)
    : id(i), date(s), info(d1,d2,d3,d4){}

void Training::print() const
{
     std::cout << "|"<< std::left << std::setw(3) << std::setfill(' ') <<id << "|";
    std::cout << std::left << std::setw(11) << std::setfill(' ') << date<< "|";
    std::cout << std::left << std::setw(19) << std::setfill(' ') << info.pullup<< "|";
    std::cout << std::left << std::setw(19) << std::setfill(' ') << info.pushup<< "|";
    std::cout << std::left << std::setw(19) << std::setfill(' ') << info.squat<< "|";
    std::cout << std::left << std::setw(5) << std::setfill(' ') << info.jumprope<<"\n";
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

void Training::serialize(QJsonObject & obj)
{
    obj["id"]=static_cast<int>(id);
    obj["date"]=QString::fromStdString(date);
    QJsonObject data;
    if(info.pullup!="")  data["pullup"]=QString::fromStdString(info.pullup);
    if(info.pushup!="")  data["pushup"]=QString::fromStdString(info.pushup);
    if(info.squat!="")  data["squat"]=QString::fromStdString(info.squat);
    if(info.jumprope!="")  data["jumprope"]=QString::fromStdString(info.jumprope);
    obj["data"]=data;

}

Training::Data::Data(std::string d1, std::string d2, std::string d3, std::string d4)
    :pullup(d1),pushup(d2),squat(d3),jumprope(d4){}
