#include "../controller.h"
#include <vector>

Controller::Controller(Model* m) : model{m} {}

uint Controller::addEmptyTraining(std::string date) const {
    return model -> addEmptyTraining(date);
    
}

void Controller::addExerciseTraining(unsigned int id, std::string nameEx, std::vector<std::string> dataEx) const {
    model -> addExerciseTraining(id, nameEx, dataEx);
}

bool Controller::removeTraining(unsigned int index) const {
    return model -> remove(index);
}

bool Controller::modifyTraining(unsigned int index, std::string category, std::string value) const {
    return model -> modify(index, category, value);
}

// commands from view
Training* Controller::getTraining(unsigned int index) const {
    return model -> at(index);
}

void Controller::getAllTrainings(std::vector<Training*>& array) const {
    model -> getAllTrainings(array);
}

unsigned int Controller::getTrainingRecordsSize() const {
    return model -> getSize();
}

void Controller::sort(bool sortById) {
    if (sortById == true)   model -> sortById();
    else    model -> sortByDate();
}

// input output
bool Controller::save(std::string path) const {
    return model -> save(path);
}

void Controller::load(std::string path) const try {
    model -> load(path);
}catch(BackendException* e){
    std::cout<<e->getMessage();
}

//user auth

bool Controller::giveCredentials(std::string user, std::string pw) {
    return model -> giveCredentials(user, pw);
}

bool Controller::addCredentials(std::string user, std::string pw, std::string name, std::string surname) {
    return model -> addCredentials(user, pw, name, surname);
}

bool Controller::logOut() {
    return model -> logOut();
}

std::string Controller::getPath() const {
    return model -> getPath();
}

bool Controller::changeCredentials(std::string newu, std::string oldu, std::string p, std::string n, std::string s) {
    return model -> changeCredentials(newu, oldu, p, n, s);
    
}

std::string Controller::getCredential(std::string type) const {
    return model -> getCredential(type);
}

std::set<std::string> Controller::getTypesExercises() const {
    std::set<std::string> result;
    model -> getTypesExercises(result);
    return result;
}

std::string Controller::printTraining(int i) const {
    return model -> printTraining(i);
}   
