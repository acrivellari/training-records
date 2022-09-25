#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <set>
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
    bool addExerciseTraining(unsigned int, std::string, std::vector<std::string>); 
    bool remove(unsigned int);
    /**
     * @param string category : has to be either "date", "exercise::data::[nameExercise]" or "exercise::name::[name_exercise]"
     */
    bool modify(unsigned int, std::string, std::string); // @par string index, category, value    ->  category either "date", "exercise:name:[name_exercise]", "exercise:data:[name_exercise]"
    
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
    void getTypesExercises(std::set<std::string>&) const;
    unsigned int getSize() const;                   
    std::vector<std::string> getYears() const;  
    std::string printTraining(int) const;    

    //input output
    bool save(std::string ="");
    void load(std::string ="");

    //user
    bool giveCredentials(std::string, std::string);
    bool addCredentials(std::string, std::string, std::string = "", std::string = "");
    bool logOut();
    std::string getPath() const;
    bool changeCredentials(std::string, std::string, std::string, std::string, std::string);
    std::string getCredential(std::string) const;

};


#endif // MODEL_H
