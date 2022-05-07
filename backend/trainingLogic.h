#ifndef TLOGIC_H
#define TLOGIC_H
#include <string>
#include <vector>
#include "training.h"
namespace trainingLogic{
    unsigned int addEmptyTraining(std::vector<Training*>&, std::string);
    bool addExerciseTraining(std::vector<Training*>&, unsigned int, std::vector<std::string>); //add to the training @par int the exercise @par std::vector<std::string>
    bool remove(std::vector<Training*>&, unsigned int);
    bool modify(std::vector<Training*>&, unsigned int, std::string, std::string); // int index, string category, string value    ->  category either "date", "exercise:name:[name_exercise]", "exercise:data:[name_exercise]"

    //basic functions for list manag
    void push_end(std::vector<Training*>&, Training*);
    bool isEmpty(const std::vector<Training*>&);
    unsigned int getHighestID(const std::vector<Training*>&);
    void clear(std::vector<Training*>&);

    Training* at (std::vector<Training*>&, unsigned int);
    unsigned int getSize(std::vector<Training*>& );                   //?
    std::vector<std::string> getYears(std::vector<Training*>&);      //?
}
#endif
