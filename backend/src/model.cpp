#include "../model.h"
#include <iomanip> //setw and .. in printall
#include <backend/backendException.h>

// constructor
Model::Model(std::string filePath) : array{std::vector<Training*>{}}, path{filePath}, inputOutput{nullptr}, userAuthentication(new UsersAuth(path+"users.json")) {}

// basic functs
void Model::push_end(Training* t) {
    trainingLogic::push_end(array, t);
}

bool Model::isEmpty() const {
    return trainingLogic::isEmpty(array);
}

unsigned int Model::getHighestID() const {
    return trainingLogic::getHighestID(array);
}

void Model::clear() {
    trainingLogic::clear(array);
}


unsigned int Model::addEmptyTraining(std::string date) {
    return trainingLogic::addEmptyTraining(array, date);
}

bool Model::addExerciseTraining(unsigned int id, std::vector<std::string> dataEx) {
    return trainingLogic::addExerciseTraining(array, id, dataEx);
}

bool Model::remove(unsigned int toRemove){
    return trainingLogic::remove(array, toRemove);
}

bool Model::modify(unsigned int toModify, std::string category, std::string value) {
    return trainingLogic::modify(array, toModify, category, value);
}


//input output
bool Model::save(std::string path) {
    return inputOutput -> save(array, path);
};

void Model::load(std::string path) {
    inputOutput -> load(array, path);
};

//user
bool Model::giveCredentials(std::string user, std::string pw) {
    if (inputOutput == nullptr && userAuthentication -> giveCredentials(user, pw)) {
        inputOutput = new JsonIO(path+user+".json");
        return true;
    }
    return false;
}

bool Model::addCredentials(std::string user, std::string pw) {
    if(inputOutput == nullptr && userAuthentication -> addCredentials(user, pw)) {
        inputOutput = new JsonIO(path+user+".json");
        return true;
    }
    return false;
}

bool Model::logOut() {
    inputOutput = nullptr;

    if (!inputOutput)   return true;
    else    return false;
}
