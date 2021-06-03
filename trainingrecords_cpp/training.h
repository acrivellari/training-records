#ifndef TRAINING_H
#define TRAINING_H
#include <iostream>
#include <QJsonObject>
#include <map>

class Training{
private:
    unsigned int id;
    std::string date;
    std::map<std::string,std::string> info;

public:
    Training(unsigned int, std::string);
    Training(unsigned int, std::string, std::map<std::string,std::string>);
    void addTraining(std::string, std::string);
    void print() const;
    unsigned int getID() const;
    std::string getYear() const;
    std::string getMonth() const;
    void serialize(QJsonObject&);

};

#endif // TRAINING_H
