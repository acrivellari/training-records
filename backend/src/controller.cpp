#include "../controller.h"

Controller::Controller(Model* m) : model{m}, inputOutput(new AwsIO()) {}

Controller::Controller(std::string filepath, Model* m) : model{m}, inputOutput{new JsonIO{filepath}} {}

void Controller::addTraining(std::string date, std::vector<std::tuple<std::string, std::string, bool>> trainingData) const {
    model->add(date,trainingData);
}

bool  Controller::removeTraining(unsigned int index) const {
    return model->remove(index);
}

bool Controller::modifyTraining(unsigned int index, std::string category, std::string value) const {
    return model->modify(index, category, value);
}

void Controller::print(int index) const {
    if (index == -1)    model->print_all();
    else    model->print(index);
}

std::vector<std::vector<std::string> > Controller::get2dvectorStrings(unsigned int index) const {
    return model->printTraining(index);
}

std::vector<std::string> Controller::getYears() const {
    return model->getYears();
}




bool Controller::save(std::vector<std::tuple<unsigned int, std::string, std::vector<std::tuple<std::string, std::string, bool>>>>& trainingRecords) const {
    std::vector<std::string> years = getYears();
    return inputOutput->save(trainingRecords, years);
}
