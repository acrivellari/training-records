#include "../trainingLogic.h"
#include "../backendException.h"

// basic functs
void trainingLogic::push_end(std::vector<Training*>& array, Training* t) {
    array.push_back(t);
}

bool trainingLogic::isEmpty(const std::vector<Training*>& array) {
    return array.size();
}

unsigned int trainingLogic::getHighestID(const std::vector<Training*>& array) {
    unsigned int result{0};
    if (array.empty())  return 0;
    for(Training* t : array)  if(t -> getID() > result)   result = t -> getID();
    return result;
}

void trainingLogic::clear(std::vector<Training*>& array) {
    array.clear();
}

std::vector<std::string> trainingLogic::getYears(std::vector<Training*>& array) {
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

unsigned int trainingLogic::addEmptyTraining(std::vector<Training*>& array, std::string date) {
    unsigned int result{getHighestID(array) + 1};
    array.push_back(Training::addEmptyTraining(result, date));
    return result;
}

bool trainingLogic::addExerciseTraining(std::vector<Training*>& array, unsigned int id, std::vector<std::string> dataEx) {
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

bool trainingLogic::remove(std::vector<Training*>& array, unsigned int toRemove){
    for(std::vector<Training*>::iterator it = array.begin(); it != array.end(); it++) {
        if((*it) -> getID() == toRemove){
            array.erase(it);
            return true;
        }
    }
    return false;
}

bool trainingLogic::modify(std::vector<Training*>& array, unsigned int toModify, std::string category, std::string value) {
    for(Training* t : array) {
        if(t -> getID() == toModify) {
            return t -> modify(category, value);
        }
    }
    return false;
}


//getters of a training
Training* trainingLogic::at(std::vector<Training*>& array, unsigned int index) {
    if (index < array.size())   return array[index];
    else    return nullptr;
}

unsigned int trainingLogic::getSize(std::vector<Training*>& array) {
    return array.size();
}
