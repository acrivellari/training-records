#ifndef TRAINING_H
#define TRAINING_H
#include <iostream>
#include <QJsonObject>
#include <map>

class Training{
    friend class Model;
private:
    unsigned int id;
    std::string date;
    std::map<std::string,std::string> info;

    unsigned int getID() const;
    std::string getYear() const;
    std::string getMonth() const;

    void serialize(QJsonObject&);
public :
    Training(unsigned int, std::string);
    Training(unsigned int, std::string, std::map<std::string,std::string>);

    void addTraining(std::string, std::string);
    bool modify(std::string, std::string);

    void print() const;
    std::map<std::string, std::string> printTraining() const;
};

#endif // TRAINING_H
