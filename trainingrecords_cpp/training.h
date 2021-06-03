#ifndef TRAINING_H
#define TRAINING_H
#include <iostream>
#include <QJsonObject>
#include <map>

class Training{
private:
    unsigned int id;
    char* date;
    std::map<char*,char*> info;

public:
    Training(unsigned int, std::string);
    void addTraining("");
    void print() const;
    unsigned int getID() const;
    std::string getYear() const;
    void serialize(QJsonObject&);

};

#endif // TRAINING_H
