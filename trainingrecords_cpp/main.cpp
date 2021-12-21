#include <iostream>
#include "model.h"
int main()
{
    Model m;
    m.load("../training-records-2021.json");
    std::map<std::string, std::string> result = m.printTraining(0);
    for(std::map<std::string, std::string>::const_iterator cit = result.begin(); cit != result.end(); cit++)
        std::cout<<cit->first<<": "<<cit->second<<std::endl;

    return 0;
}
