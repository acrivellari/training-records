#include "../backendException.h"

BackendException::BackendException(const char* message) : msg(message) {}
/*
const char* BackendException::what() const noexcept { 
    return msg;
}
*/
