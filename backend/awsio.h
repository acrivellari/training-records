#ifndef AWSIO_H
#define AWSIO_H

#include "io.h"

class AwsIO : public IO {
    int a;
public:
    AwsIO();
    void load(Model*, std::string ="") const override;
    bool save(Model*, std::string ="") const override;
    virtual ~AwsIO(){};
};

#endif
