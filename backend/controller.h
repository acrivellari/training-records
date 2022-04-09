#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "../frontend/view.h"
#include "io.h"

class Controller {
public:
    Model* model;
    //View* view;
    //IO* inputOutput;

    Controller(Model* = new Model());

    void addTraining(std::string date, std::vector<std::tuple<std::string, std::string, bool>> trainingData) const;
    bool removeTraining(unsigned int) const;
    bool modifyTraining(unsigned int index, std::string category, std::string value) const;

    void print(int index =-1) const;
    std::vector<std::vector<std::string>> get2dvectorStrings(unsigned int) const;

    std::vector<std::string> getYears() const;
    //commands from view



};

#endif
