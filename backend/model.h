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

    //basic function for model, higher-level of list manag
    void add(std::string, std::vector<std::tuple<std::string, std::string, bool>>); //give training as vector of string (name exercise) and pair of reps and type
    bool remove(unsigned int);
    bool modify(unsigned int, std::string, std::string); // int index, string category, string value
                                                         //     ->  category either "date", "exercise:name:[name_exercise]", "exercise:data:[name_exercise]"
    //basic functions for list manag
    void push_end(Training*);
    bool isEmpty() const;
    unsigned int getHighestID() const;
    std::vector<std::string> getYears() const;
    void getAllTrainings(std::vector<Training*>&) const;

    // print functions
    std::vector<std::vector<std::string>> printTraining(unsigned int i) const;
    void print_all() const;
    void print(unsigned int);


};


#endif // MODEL_H
