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
        bool tType; //0 is reps, 1 is seconds
        std::vector<unsigned int> tSets;

        TrainingExercise(std::string, std::vector<unsigned int>, bool = false);
        TrainingExercise(std::string, std::vector<unsigned int>, std::string = "reps");

        static bool getType(std::string);
        static std::string getType(bool);
        std::string getSets() const;
        std::vector<std::string> getExercise() const;
    };

    unsigned int id;
    TrainingDate tDate;
    std::vector<TrainingExercise*> tData;
    //training is formed by id tData and tDate
    //tDate contains the date of the training while tData the exercises and their reps and set of the training

    Training(unsigned int, std::string);
    ~Training();

    bool modifyTrainingDate(std::string);
    bool modifyTrainingExercise(std::string, std::string);

    //support functs
    std::vector<unsigned int> string2sets(std::string, bool);
    static std::vector<int> string2dateInt(std::string);
    static std::string type2string(bool);
    static std::string stringDate(int);//transform month day or year into string format, in case adding some 0 to pad (ex day 1->day 01)
    unsigned int getHighestIdExercise() const;

public:

    //add, modify and remove training or training data              // we give for assumed that sets are well written in form: number["]-number["]-number.... etc with " optional
    void addTrainingExercise(std::string, std::string, bool = false);   // training sets separated by: -
    void addTrainingExercise(std::string, std::string, std::string = "reps");
    static Training* addEmptyTraining(unsigned int, std::string);

    bool modify(std::string, std::string);
    void removeExercise(std::string);

    void print() const;
    std::vector<std::vector<std::string>> printTraining() const;

    //getters-setters
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    std::string getDate(std::string) const;
    unsigned int getID() const;
    unsigned int getNExercises() const;
    std::vector<std::string> getExercise(unsigned int) const;
    void setYear(int);
    void setMonth(int);
    void setDay(int);
};

#endif // TRAINING_H
