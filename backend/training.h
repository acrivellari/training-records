#ifndef TRAINING_H
#define TRAINING_H
#include <iostream>
#include <QJsonObject>
#include <map>
#include <vector>

class Training {
private:
    Training(unsigned int, std::string);

    class TrainingDate {
    public:
        unsigned int year, month, day;
        TrainingDate(int =0, int =0, int =0);
        TrainingDate(std::string);
    };

    class TrainingExercise {
    public:
        std::string tName;
        bool tType; //0 is reps, 1 is seconds
        std::vector<unsigned int> tSets;
        TrainingExercise(std::string, std::vector<unsigned int>, bool = false);
    };

    unsigned int id;
    TrainingDate tDate;
    std::vector<TrainingExercise*> tData;
    //training is formed by id tData and tDate
    //tDate contains the date of the training while tData the exercises and their reps and set of the training

public:
    ~Training();

    //add, modify and remove training or training data              // we give for assumed that sets are well written in form: number["]-number["]-number.... etc with " optional
    void addTrainingExercise(std::string, std::string, bool = false);   // training sets separated by: -
    static Training* addEmptyTraining(unsigned int, std::string);
    bool modify(std::string, std::string);
    bool modifyTrainingDate(std::string);
    bool modifyTrainingExercise(std::string, std::string);
    void removeExercise(std::string);

    void print() const;
    std::vector<std::vector<std::string>> printTraining() const;

    void getTraining(unsigned int&, std::string&, std::vector<std::tuple<std::string, std::string, bool>>& trainingRecord);

    //support functs
    std::vector<unsigned int> string2sets(std::string, bool);
    static std::vector<int> string2dateInt(std::string);
    static std::string type2string(bool);
    static std::string stringDate(int);//transform month day or year into string format, in case adding some 0 to pad (ex day 1->day 01)

    //getters-setters
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    unsigned int getID() const;
    void setYear(int);
    void setMonth(int);
    void setDay(int);
};

#endif // TRAINING_H
