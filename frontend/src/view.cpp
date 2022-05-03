#include "../view.h"

View::View(Controller *c) : controller{c}{}

//DUMMY VIEW *é********************

void View::addEmptyTraining(std::string date) const
{
    controller -> addEmptyTraining(date);
}

void View::addExerciseTraining(unsigned int i, std::vector<std::string> v) const
{
    controller -> addExerciseTraining(i,v);
}

bool View::removeTraining(unsigned int i) const
{
    controller -> removeTraining(i);
}

bool View::modifyTraining(unsigned int index, std::string category, std::string value) const
{
    controller -> modifyTraining(index, category, value);
}

bool View::save(std::string s) const
{
    controller -> save(s);
}

void View::load(std::string l) const
{
    controller -> load(l);
}

void View::giveCredentials(std::string u, std::string p)
{
    controller -> giveCredentials(u, p);
}

void View::addCredentials(std::string u, std::string p)
{
    controller -> addCredentials(u,p);
}

void View::logOut()
{
    controller -> logOut();
}
