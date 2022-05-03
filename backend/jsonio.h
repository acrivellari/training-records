#ifndef JSONIO_H
#define JSONIO_H

#include "io.h"


class JsonIO : public IO {
    std::string path;
public:
    JsonIO(std::string);
    void load() const override;
    bool save() const override;
    virtual ~JsonIO(){};
};

#endif
