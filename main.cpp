#include <iostream>
#include "backend/controller.h"
#include <tuple>
int main()
{/*
    Model m;
    m.load("../../Repo/github_training-records/training-records-2021.json");
    std::map<std::string, std::string> result = m.printTraining(1);
    for(std::map<std::string, std::string>::const_iterator cit = result.begin(); cit != result.end(); cit++)
        std::cout<<cit->first<<": "<<cit->second<<std::endl;
*/
    Model* m = new Model();
    Controller c{m};
    //c.print(true, 1);
    std::vector<std::tuple<std::string, std::string, bool>> toSend{};
    std::tuple<std::string, std::string, bool> prova = std::make_tuple("ciao", "1-1", true);
    toSend.push_back(prova);
    std::string date{"2022-02-21"};
    c.addEmptyTraining(date);
    c.print(1);
    std::cout<<"ciao";
    c.modifyTraining(1, "exercise:name:ciao", "ciaoo");
    c.modifyTraining(1, "exercise:data:ciaoo", "2-2");
    std::vector<std::vector<std::string>> s = c.get2dvectorStrings(1);
    for(std::vector<std::string>& a : s){
        for(std::string b : a)  std::cout<<b<<" ";
    }
    return 0;
}
