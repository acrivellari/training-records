#ifndef BEXCEPTION_H
#define BEXCEPTION_H

#include <exception>
class BackendException : public std::exception {
private:
    const char* msg;

public :
    BackendException(const char*);
};

#endif
