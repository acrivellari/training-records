#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>
#include "backendException.h"
#include "training.h"

class IO {
public:
    virtual void load(std::vector<Training*>&, std::string ="") const =0;
    virtual bool save(const std::vector<Training*>&, std::string ="") const =0;
    virtual ~IO(){};

};

#endif
