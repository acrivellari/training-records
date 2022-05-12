#ifndef AWSIO_H
#define AWSIO_H

#include "io.h"

class AwsIO : public IO {
    int a;
public:
    AwsIO();
    void load(std::vector<Training*>&, std::string ="") const override;
    bool save(const std::vector<Training*>&, std::string ="") const override;
    virtual ~AwsIO(){};
};

#endif
