#ifndef JSONIO_H
#define JSONIO_H

#include "io.h"


class JsonIO : public IO {
    std::string path;
public:
    JsonIO(std::string);
    void load(Model*, std::string ="") const override;
    bool save(Model*, std::string ="") const override;
    virtual ~JsonIO(){};
};

#endif
