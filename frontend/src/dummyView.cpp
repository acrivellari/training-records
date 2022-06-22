#include "../dummyView.h"

DummyView::DummyView(Controller *c) : controller{c}{}

//DUMMY DummyView *é********************

void DummyView::addEmptyTraining(std::string date) const
{
    controller -> addEmptyTraining(date);
}

void DummyView::addExerciseTraining(unsigned int i, std::vector<std::string> v) const
{
    controller -> addExerciseTraining(i,v);
}

bool DummyView::removeTraining(unsigned int i) const
{
    controller -> removeTraining(i);
}

bool DummyView::modifyTraining(unsigned int index, std::string category, std::string value) const
{
    controller -> modifyTraining(index, category, value);
}

bool DummyView::save(std::string s) const
{
    controller -> save(s);
}

void DummyView::load(std::string l) const
{
    controller -> load(l);
}

void DummyView::giveCredentials(std::string u, std::string p)
{
    controller -> giveCredentials(u, p);
}

void DummyView::addCredentials(std::string u, std::string p)
{
    controller -> addCredentials(u,p);
}

void DummyView::logOut()
{
    controller -> logOut();
}
