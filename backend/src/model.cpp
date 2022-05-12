#include "../model.h"
#include <iomanip> //setw and .. in printall
#include <backend/backendException.h>

// constructor
Model::Model(std::string filePath) : array{std::vector<Training*>{}}, path{filePath}, inputOutput{nullptr}, userAuthentication(new UsersAuth(path+"users.json")) {}

// basic functs
void Model::push_end(Training* t) {
    array.push_back(t);
}

bool Model::isEmpty() const {
    return array.empty();
}

unsigned int Model::getHighestID() const {
    unsigned int result {0};
    if (array.size() > 0) {
        for (Training* t : array) {
            if (t -> getID() > result) {
                result = t -> getID();
            }
        }
    }
    return result;
}

void Model::clear() {
    array.clear();
}

Training* Model::at(unsigned int index) const {
    Training* result = nullptr;
    if (index < array.size()){
        result = array[index];
    }
    return result;
}

unsigned int Model::getSize() const {
    return array.size();
}

std::vector<std::string> Model::getYears() const {
    std::vector<std::string> years {};
    for (Training* t : array) {
        if (years.empty()) {
            years.push_back(t -> getDate("year"));
        }else {
            bool absent{true}
            for(std::string& storedYear : years) {
                if (storedYear == t -> getDate("year")) {
                    absent = false;
                }
            }
            if (absent == true) {
                years.push_back(t -> getDate("years"));
            }
        }
    }
    return years;
}

unsigned int Model::addEmptyTraining(std::string date) {
    unsigned int result{0};
    if (!isEmpty()) {
        result = getHighestID(array) + 1;
    }
    array.push_back(addEmptyTraining(result, date));
    return result;
}

bool Model::addExerciseTraining(unsigned int id, std::vector<std::string> dataEx) {
    bool returnValue = false;
    if (dataEx.size() < 2 || dataEx.size() > 4) {
        throw new BackendException("This exercise is not well formed.");
    }
    for (Training* t : array) {
        if (t -> getID() == id) {
            if (dataEx.size() == 2) {
                t -> addTrainingExercise(dataEx.at(0), dataEx.at(1));
            }else {
                t -> addTrainingExercise(dataEx.at(0), dataEx.at(1), dataEx.at(2));
            }
            returnValue = true;
        }
    }
    return returnValue;
}    

bool Model::remove(unsigned int toRemove){
    bool returnValue = false;
    for (std::vector<Training*>::iterator it = array.begin(); it != array.end(); it++) {
        if ((*it) -> getID() == toRemove) {
            array.erase(it);
            returnValue = true;
        }
    }
    return returnValue;
}

bool Model::modify(unsigned int toModify, std::string category, std::string value) {
    bool returnValue = false;
    for (Training* t : array) {
        if (t -> getID() == toModify) {
            returnValue = t -> modify(category, value);
        }
    }
    return returnValue;    
}


//input output
bool Model::save(std::string path) {
    return inputOutput -> save(array, path);
};

void Model::load(std::string path) {
    array.clear();
    std::vector<Training*> loaded{};
    inputOutput -> load(loaded, path);
    array = loaded;
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
