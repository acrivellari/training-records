#ifndef APPSERVICE_H
#define APPSERVICE_H

#include <string>

namespace Models {
    class AppService {
    public:
        AppService();
        ~AppService();
        std::string GetString();
    };
}

#endif // APPSERVICE_H

