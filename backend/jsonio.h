#ifndef JSONIO_H
#define JSONIO_H

#include "io.h"


class JsonIO : public IO {
    std::string path;
public:
    JsonIO(std::string);
    bool load() const override;
    bool save(std::vector<std::tuple<unsigned int, std::string, std::vector<std::tuple<std::string, std::string, bool>>>>&, std::vector<std::string>&) override;
    virtual ~JsonIO(){};
};

#endif
