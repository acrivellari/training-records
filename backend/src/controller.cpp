#include "../controller.h"

Controller::Controller(Model* m) : model{m}, inputOutput(new AwsIO()) {}

Controller::Controller(std::string filepath, Model* m) : model{m}, inputOutput{new JsonIO{filepath}} {}

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


bool Controller::save() const {
    return inputOutput -> save();
}

void Controller::load() const try {
    inputOutput -> load();
}catch(BackendException* e){
    std::cout<<e->getMessage();
}
