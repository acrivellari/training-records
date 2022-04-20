#include "../model.h"
#include <iomanip> //setw and .. in printall
#include <backend/backendException.h>

void Model::push_end(Training* t) {
    array.push_back(t);
}

bool Model::isEmpty() const {
    return array.size();
}

unsigned int Model::getHighestID() const {
    unsigned int result{0};
    for(Training* t : array)  if(t -> getID() > result)   result = t -> getID();
    return result;
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

void Model::add(std::string date, std::vector<std::tuple<std::string, std::string, bool>> tEx) {
    Training* t = Training::addEmptyTraining(getHighestID()+1, date);
    for(std::tuple<std::string, std::string, bool> singleExercise : tEx){
        t -> addTrainingExercise(std::get<0>(singleExercise), std::get<1>(singleExercise), std::get<2>(singleExercise));
    }
    array.push_back(t);
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

std::vector<std::vector<std::string>> Model::printTraining(unsigned int i) const {
    for(const Training* t : array) {
        if (t -> getID() == i)    return t -> printTraining();
    }
    return std::vector<std::vector<std::string>>{};
}

void Model::print_all() const {
    std::cout << "Print all TRAININGS:\n";
    std::cout << std::left << std::setw(4) << std::setfill(' ') << "|Id";
    std::cout << std::left << std::setw(12) << std::setfill(' ') << "|Date";
    std::cout << std::left << std::setw(20) << std::setfill(' ') << "|Jump Rope";
    std::cout << std::left << std::setw(20) << std::setfill(' ') << "|Pullup";
    std::cout << std::left << std::setw(20) << std::setfill(' ') << "|Pushup";
    std::cout << std::left << std::setw(5) << std::setfill(' ') << "|Squat\n";
    for(const Training* t : array)  t -> print();
}

void Model::print(unsigned int toPrint) {
    for(Training* t : array) {
        if(t -> getID() == toPrint) {
            t -> print();
        }
    }
}

//getters of a training
std::string Model::getDateTraining(unsigned int idTr) {
    for(const Training* t : array) {
        if (t -> getID() == idTr) return t->getDate("all");
    }
    throw new BackendException("This id does not exist.");
}

unsigned int Model::getNumberExercises(unsigned int idTr) {
    for(const Training* t : array) {
        if (t -> getID() == idTr)   return t -> getNExercises();
    }
    throw new BackendException("This id does not exist.");
}

std::vector<std::string> Model::getExercise(unsigned int idTr, unsigned int idEx) {
    for (const Training* t : array) {
        if (t -> getID() == idTr)   return t -> getExercise(idEx);
    }
    throw new BackendException("This id does not exist.");
}


