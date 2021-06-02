#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "training.h"

class Model
{
private:
    std::vector<Training*> list;
    std::vector<Training*> selected;

    void push_end(Training*);
    void substitute(Training*);
    bool isEmpty() const;
public:
   // Model()=default;
    ~Model()=default;
    //filters
    void save(std::string) const;
    void load(std::string);

    void print_selected() const;
    void print_all() const;



};

#endif // MODEL_H
