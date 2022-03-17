#ifndef TRAINING_H
#define TRAINING_H
#include <iostream>
#include <QJsonObject>
#include <map>
class Training{
    friend class Model;
private:
    class TrainingDate{
    public:
        unsigned int year, month, day;
        TrainingDate(int, int, int);
        TrainingDate(std::string);
    };
    class TrainingExercise{
    public:
        std::string tName;
        bool tType; //0 is reps, 1 is seconds
        std::vector<unsigned int> tSets;
        TrainingExercise(std::string, std::vector<unsigned int>, bool = false);
    };
    unsigned int id;
    TrainingDate tDate;
    std::vector<TrainingExercise*> tData;



    std::vector<unsigned int> string2sets(std::string, bool);
    static std::vector<int> string2date(std::string);
    static std::string addZeroDate(int);
    static std::string type2string(bool);

public:
    Training(unsigned int, std::string);
    ~Training();
                                                                    // we give for assumed that sets are well written in form: number[']-number[']-number.... etc with ' optional
    void addExerciseData(std::string, std::string, bool = false);   // training sets separated by: -
    void modifyTrainingDate(std::string);
    bool modifyTrainingExercise(std::string, std::string);
    void removeExercise(std::string);

    void print() const;
    std::vector<std::vector<std::string>> printTraining() const;

    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    void setYear(int);
    void setMonth(int);
    void setDay(int);



};

#endif // TRAINING_H
