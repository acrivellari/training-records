#ifndef MODEL_H
#define MODEL_H
#include <vector>
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
    //filters
    void save(std::string) const;
    void load(std::string);
    void add(std::string, std::string, std::string, std::string, std::string);

    //void print_selected() const;
    void print_all() const;


};

#endif // MODEL_H
