#include "../model.h"
#include <iomanip> //setw and .. in printall
#include <backend/backendException.h>

void Model::push_end(Training* t) {
    array.push_back(t);
}

bool Model::isEmpty() const {
    return array.size();
}

int Model::getHighestID() const {
    unsigned int result{0};
    if (array.empty())  return -1;
    for(Training* t : array)  if(t -> getID() > result)   result = t -> getID();
    return result;
}

void Model::clear() {
    array.clear();
}

std::vector<std::string> Model::getYears() const {
    std::vector<std::string> years{};
    for(Training* t : array){
        if(years.size() == 0)   years.push_back(t -> getDate("year"));
        else{
            bool counter{true};
            for(std::string& eachYear : years){
                if(eachYear == t -> getDate("year")){
                    counter = false;
                }
            }
            if (counter == true)    years.push_back(t -> getDate("year"));
        }
    }
    return years;
}

unsigned int Model::addEmptyTraining(std::string date) {
    int result{getHighestID() + 1};
    array.push_back(Training::addEmptyTraining(result, date));
    return result;
}

bool Model::addExerciseTraining(unsigned int id, std::vector<std::string> dataEx) {
    if (dataEx.size() < 2) throw new BackendException("This exercise is not well formed.");
    for (Training* t : array) {
        if (t -> getID() == id) {
            if (dataEx.size() == 2) t -> addTrainingExercise(dataEx.at(0), dataEx.at(1));
            else    t -> addTrainingExercise(dataEx.at(0), dataEx.at(1), dataEx.at(2));
            return true;
        }
    }
    return false;
}

bool Model::remove(unsigned int toRemove){
    for(std::vector<Training*>::iterator it = array.begin(); it != array.end(); it++) {
        if((*it) -> getID() == toRemove){
            array.erase(it);
            return true;
        }
    }
    return false;
}

bool Model::modify(unsigned int toModify, std::string category, std::string value) {
    for(Training* t : array) {
        if(t -> getID() == toModify) {
            return t -> modify(category, value);
        }
    }
    return false;
}


//getters of a training
Training* Model::at(unsigned int index) const {
    if (index < array.size())   return array[index];
    else    return nullptr;
}

unsigned int Model::getSize() const {
    return array.size();
}



