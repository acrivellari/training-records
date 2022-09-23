#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "training.h"
#include "jsonio.h"
#include "usersauth.h"

class Model {
private:
    std::vector<Training*> array;
    std::string path;
    IO* inputOutput;
    UsersAuth* userAuthentication;

public:
    Model(std::string = "");
    ~Model() = default;
    //basic functions for model, higher-level of list manag
    unsigned int addEmptyTraining(std::string);
    bool addExerciseTraining(unsigned int, std::vector<std::string>); //add to the training @par int the exercise @par std::vector<std::string>
    bool remove(unsigned int);
    bool modify(unsigned int, std::string, std::string); // int index, string category, string value    ->  category either "date", "exercise:name:[name_exercise]", "exercise:data:[name_exercise]"
    
    //basic functions for list manag
    void push_end(Training*);
    bool isEmpty() const;
    unsigned int getHighestID() const;
    void clear();

    //sort
    static bool sortObjById(Training*, Training*);
    static bool sortObjByDate(Training*, Training*);
    void sortById();
    void sortByDate();

    Training* at (unsigned int) const;
    void getAllTrainings(std::vector<Training*>&) const;
    unsigned int getSize() const;                   
    std::vector<std::string> getYears() const;      

    //input output
    bool save(std::string ="");
    void load(std::string ="");

    //user
    bool giveCredentials(std::string, std::string);
    bool addCredentials(std::string, std::string, std::string = "", std::string = "");
    bool logOut();
    std::string getPath() const;

};


#endif // MODEL_H
