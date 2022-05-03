#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "../frontend/view.h"
#include "jsonio.h"
#include "awsio.h"

class Controller {
public:
    Model* model;
    //View* view;
    IO* inputOutput;

    Controller(Model* = new Model());
    Controller(std::string, Model* = new Model());

    void addEmptyTraining(std::string date) const;
    void addExerciseTraining(unsigned int, std::vector<std::string>) const;
    bool removeTraining(unsigned int) const;
    bool modifyTraining(unsigned int index, std::string category, std::string value) const;

    //commands from view

    //input output
    bool save(std::string ="") const;
    void load(std::string ="") const;


};

#endif
