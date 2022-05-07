#ifndef JSONIO_H
#define JSONIO_H

#include "io.h"


class JsonIO : public IO {
private :
    std::string path;
public:
    JsonIO(std::string);
    void load(std::vector<Training*>&, std::string ="") const override;
    bool save(std::vector<Training*>&, std::string ="") const override;
    virtual ~JsonIO(){};
};

#endif
