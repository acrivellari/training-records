#include <iostream>

using namespace std;
#include "model.h"
int main()
{
    Model m;
    m.load("../training-records-2021.json");
    m.print_all();
    m.add("2020-12-12","","50","10","");
    m.save("../prova.json");
    return 0;
}
