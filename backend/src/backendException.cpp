#include "../backendException.h"

BackendException::BackendException(std::string message) : msg(message) {}

std::string BackendException::getMessage() const {
    return msg;
}
