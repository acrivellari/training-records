#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "training.h"

class Model {
private:
    std::vector<Training*> array;
public:
    //input output funct
    //void save(std::string) const;
    //void load(std::string);
    //static void serialize(Training*, QJsonObject&);

    //basic functions for model, higher-level of list manag
    unsigned int addEmptyTraining(std::string);
    bool addExerciseTraining(unsigned int, std::vector<std::string>); //add to the training @par int the exercise @par std::vector<std::string>
    bool remove(unsigned int);
    bool modify(unsigned int, std::string, std::string); // int index, string category, string value    ->  category either "date", "exercise:name:[name_exercise]", "exercise:data:[name_exercise]"

    //basic functions for list manag
    void push_end(Training*);
    bool isEmpty() const;
    int getHighestID() const;
    std::vector<std::string> getYears() const;

    //getters of a training, given a id of a training
    std::string getDateTraining(unsigned int);
    unsigned int getNumberExercises(unsigned int);
    std::vector<std::string> getExercise(unsigned int, unsigned int);

    // print functions
    std::vector<std::vector<std::string>> printTraining(unsigned int i) const;
    void print_all() const;
    void print(unsigned int);


};


#endif // MODEL_H
