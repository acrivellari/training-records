#ifndef AWSIO_H
#define AWSIO_H

#include "io.h"

class AwsIO : public IO {
    int a;
public:
    AwsIO();
    bool load() const override;
    bool save(std::vector<std::tuple<unsigned int, std::string, std::vector<std::tuple<std::string, std::string, bool>>>>&, std::vector<std::string>&) override;
    virtual ~AwsIO(){};
};

#endif
