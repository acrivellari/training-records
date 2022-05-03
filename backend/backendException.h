#ifndef BEXCEPTION_H
#define BEXCEPTION_H

#include <exception>
#include <string>
class BackendException : public std::exception {
private:
    std::string msg;

public :
    BackendException(std::string);
    std::string getMessage() const;
};

#endif
