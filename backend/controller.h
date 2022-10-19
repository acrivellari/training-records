#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <set>
#include "model.h"
#include "../frontend/view.h"

class Controller {
public:
    Model* model;
    View* view;
    Controller(Model*);

    void setGUI(View*);

    uint addEmptyTraining(std::string date) const;
    void addExerciseTraining(unsigned int, std::string, std::vector<std::string>) const;
    bool removeTraining(unsigned int) const;
    bool modifyTraining(unsigned int index, std::string category, std::string value) const;

    //commands from view
    Training* getTraining(unsigned int) const;
    void getAllTrainings(std::vector<Training*>&) const;
    unsigned int getTrainingRecordsSize() const;
    void sort(bool =false);    //false -> sort_byDate | true -> sort_byID
    std::set<std::string> getTypesExercises() const;
    std::string printTraining(int ) const;

    //input output
    bool save(std::string ="") const;
    void load(std::string ="") const;

    //user
    bool giveCredentials(std::string, std::string);
    bool addCredentials(std::string, std::string, std::string = "", std::string = "");
    bool logOut();
    bool changeCredentials(std::string, std::string, std::string, std::string, std::string);
    std::string getCredential(std::string) const;
    std::string getPath() const;

};

#endif
