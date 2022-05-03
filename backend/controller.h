#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "../frontend/view.h"
#include "jsonio.h"
#include "awsio.h"
#include "usersauth.h"

class Controller {
public:
    std::string path;
    Model* model;
    //View* view;
    IO* inputOutput;
    UsersAuth* userAuthentication;

    Controller(std::string, Model* = new Model());

    void addEmptyTraining(std::string date) const;
    void addExerciseTraining(unsigned int, std::vector<std::string>) const;
    bool removeTraining(unsigned int) const;
    bool modifyTraining(unsigned int index, std::string category, std::string value) const;

    //commands from view

    //input output
    bool save(std::string ="") const;
    void load(std::string ="") const;

    //user
    void giveCredentials(std::string, std::string);


};

#endif
