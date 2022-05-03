#ifndef AWSIO_H
#define AWSIO_H

#include "io.h"

class AwsIO : public IO {
    int a;
public:
    AwsIO();
    void load() const override;
    bool save() const override;
    virtual ~AwsIO(){};
};

#endif
