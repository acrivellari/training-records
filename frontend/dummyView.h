#ifndef DVIEW_H
#define DVIEW_H

#include "view.h"

class DummyView : public View {
private :
    Controller* controller;
public :
    DummyView(Controller*);

    //dummy view to make it work::::::
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
    void addCredentials(std::string, std::string);
    void logOut();

    virtual ~DummyView(){};
};

#endif
