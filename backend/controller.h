#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller {
public:
    Model* model;
    //View* view;

    Controller(Model* = new Model());

    void addEmptyTraining(std::string date) const;
    void addExerciseTraining(unsigned int, std::vector<std::string>) const;
    bool removeTraining(unsigned int) const;
    bool modifyTraining(unsigned int index, std::string category, std::string value) const;

    //commands from view

    //input output
    bool save(std::string ="") const;
    void load(std::string ="") const;

    //user
    bool giveCredentials(std::string, std::string);
    bool addCredentials(std::string, std::string, std::string = "", std::string = "");
    bool logOut();
    std::string getPath() const;


};

#endif
