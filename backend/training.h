#ifndef TRAINING_H
#define TRAINING_H
#include <iostream>
#include <QJsonObject>
#include <map>
#include <vector>

class Training {
private:

    class TrainingDate {
    public:
        unsigned int year, month, day;
        TrainingDate(int =0, int =0, int =0);
        TrainingDate(std::string);
    };

    class TrainingExercise {
    public:
        unsigned int idExercise;
        std::string tName;
        bool tType; 
            //false -> reps
            //true -> seconds
        std::vector<unsigned int> tSets;

        TrainingExercise(std::string, std::vector<unsigned int>, bool = false);
        TrainingExercise(std::string, std::vector<unsigned int>, std::string = "reps");

        static bool getType(std::string);
        static std::string getType(bool);
        std::string getSets() const;
        std::vector<std::string> getExercise() const;
    };
    
    unsigned int id;                        //index based on when it was added the training
    TrainingDate tDate;                     //date of the training
    std::vector<TrainingExercise*> tData;   //training exercises and their reps and set
     
    Training(unsigned int, std::string);
    ~Training();

    //support functs
    bool operator < (const Training&) const;
    static bool sortById(const Training*, const Training*); 
    bool modifyTrainingDate(std::string);
    bool modifyTrainingExercise(std::string, std::string);
    std::vector<unsigned int> string2sets(std::string, bool);
    static bool getType(std::string);
    static std::vector<int> string2dateInt(std::string);
    static std::string type2string(bool);
    static std::string stringDate(int);     //in case adding some 0 to pad (ex day 1->day 01)

public:

    //add, modify and remove training or training data              
    // we give for assumed that sets are well written in form: number["]-number["]-number.... etc with " optional
    void addTrainingExercise(std::string, std::string, bool);       
    void addTrainingExercise(std::string, std::string, std::string);
    void addTrainingExercise(std::string, std::string);
    static Training* addEmptyTraining(unsigned int, std::string);
    bool modify(std::string, std::string);
    void removeExercise(std::string);
    

    void print() const;
    std::vector<std::vector<std::string>> printTraining() const;

    //getters-setters
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    std::string getDate(std::string = "all") const; //options : year month day all
    unsigned int getID() const;
    unsigned int getNExercises() const;             //number ex
    std::vector<std::string> getExercise(unsigned int) const;
    void setYear(int);
    void setMonth(int);
    void setDay(int);
};

#endif // TRAINING_H
