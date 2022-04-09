#include <exception>
class BackendException : public std::exception {
private:
    const char* msg;

public :
    BackendException(const char*);
    const char* what() const;

};

BackendException::BackendException(const char* message) : msg(message) {}

const char* BackendException::what() const{
    return msg;
}
