#include <iostream>

using namespace std;
#include "model.h"
int main()
{
    Model m;
    m.load("../training-records-2021.json");
    m.print_all();

    return 0;
}
