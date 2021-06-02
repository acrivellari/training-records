#ifndef TRAINING_H
#define TRAINING_H
#include <iostream>

class Training{
private:
    class Data{ //!TODO: to decide if mantain like this (extend or change completely)
    public:
        std::string pullup;
        std::string pushup;
        std::string squat;
        std::string jumprope;
        Data(std::string ="",std::string ="",std::string ="",std::string ="");

    };
    unsigned int id; //!TODO: put identifier automatic based on last identifier training
    std::string date;
    Data info;

public:
    Training(unsigned int, std::string, std::string ="",std::string ="",std::string ="",std::string ="");

};

#endif // TRAINING_H
