#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include <map>
#include "training.h"

class Model
{
private:
    std::vector<Training*> list;
    //std::vector<Training*> selected;

    void push_end(Training*);
    bool isEmpty() const;
    unsigned int getHighestID() const;
    std::vector<std::string> getYears() const;
public:
    Model()=default;
    ~Model()=default;

    void save(std::string) const;
    void load(std::string);
    static void serialize(Training*, QJsonObject&);

    void add(std::string, std::map<std::string,std::string>);
    bool modify(unsigned int, std::string, std::string);
    bool remove(unsigned int);

    std::map<std::string, std::string> printTraining(unsigned int i) const;
    void print_all() const;
    void print(unsigned int);

};


#endif // MODEL_H
