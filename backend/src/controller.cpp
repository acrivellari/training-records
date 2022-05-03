#include "../controller.h"


Controller::Controller(std::string p, Model* m) : path{p}, model{m}, inputOutput{nullptr}, userAuthentication(new UsersAuth(path+"users.json")) {}

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


bool Controller::save(std::string path) const {
    return inputOutput -> save(model, path);
}

void Controller::load(std::string path) const try {
    inputOutput -> load(model, path);
}catch(BackendException* e){
    std::cout<<e->getMessage();
}

//user auth

void Controller::giveCredentials(std::string user, std::string pw) {
    if (inputOutput == nullptr && userAuthentication -> giveCredentials(user, pw)) {
        inputOutput = new JsonIO(path+user+".json");
    }
}

void Controller::addCredentials(std::string user, std::string pw) {
    if(inputOutput == nullptr && userAuthentication -> addCredentials(user, pw)) {
        inputOutput = new JsonIO(path+user+".json");
    }
}

void Controller::logOut() {
    inputOutput = nullptr;
}
