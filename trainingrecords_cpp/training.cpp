#include "training.h"

Training::Training(unsigned int i, std::string s, std::string d1, std::string d2, std::string d3, std::string d4)
    : id(i), date(s), info(d1,d2,d3,d4){}

Training::Data::Data(std::string d1, std::string d2, std::string d3, std::string d4)
    :pullup(d1),pushup(d2),squat(d3),jumprope(d4){}
