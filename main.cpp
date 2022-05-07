#include <iostream>
#include "frontend/view.h"
namespace main_testing{
    void functions() {
        /*
            Model m;
            m.load("../../Repo/github_training-records/training-records-2021.json");
            std::map<std::string, std::string> result = m.printTraining(1);
            for(std::map<std::string, std::string>::const_iterator cit = result.begin(); cit != result.end(); cit++)
                std::cout<<cit->first<<": "<<cit->second<<std::endl;


            c.giveCredentials("evilcrive", "evilcrive");
            c.load();
            c.save("ciao");

            //c.print(true, 1);
            std::vector<std::tuple<std::string, std::string, bool>> toSend{};
            std::tuple<std::string, std::string, bool> prova = std::make_tuple("ciao", "1-1", true);
            toSend.push_back(prova);
            std::string date{"2022-02-21"};
            c.addEmptyTraining(date);
            std::cout<<"ciao";
            c.modifyTraining(1, "exercise:name:ciao", "ciaoo");
            c.modifyTraining(1, "exercise:data:ciaoo", "2-2");
            c.load();
          c.save("ciao");*/
    }
    void other(View* v, unsigned int value) {
        if (value == 0) return;
        v -> giveCredentials("evilcrive", "evilcrive");
        v->load();
        v->addEmptyTraining("2050-10-12");
        v->modifyTraining(1, "exercise:name:pullup", "ciaoo");
        v->modifyTraining(1, "exercise:data:ciaoo", "2-2");
        v->save("ciao");
    }
}

int main() {
    View v {new Controller{new Model("../github_training-records/backend/resources/")}};
    main_testing::other(&v, 0);
}
