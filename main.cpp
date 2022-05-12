#include <iostream>
#include "frontend/view.h"
namespace main_testing{
    void testFunctionA() {
        v -> giveCredentials("evilcrive", "evilcrive");
        v->load();
        v->addEmptyTraining("2050-10-12");
        v->modifyTraining(1, "exercise:name:pullup", "ciaoo");
        v->modifyTraining(1, "exercise:data:ciaoo", "2-2");
        v->save("ciao");
    }
    void testMain(View* v, unsigned int value) {
        if (value == 1) testFunctionA();

    }
}

int main() {
    View v {new Controller{new Model("../github_training-records/backend/resources/")}};
    main_testing::testMain(&v, 0);
}
