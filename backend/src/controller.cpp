#include "../controller.h"


Controller::Controller(Model* m) : model{m} {}

void Controller::addEmptyTraining(std::string date) const {
    model -> addEmptyTraining(date);
}

void Controller::addExerciseTraining(unsigned int id, std::vector<std::string> dataEx) const {
    model -> addExerciseTraining(id, dataEx);
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

unsigned int Controller::getTrainingRecordsSize() const {
    return model -> getSize();
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
