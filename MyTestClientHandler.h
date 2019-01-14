//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_MYTESTCLIENTHANDLER_H
#define ALGOPROJECT_MYTESTCLIENTHANDLER_H



#include <cstring>
#include <zconf.h>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
    Solver *solver;
public:
    MyTestClientHandler(Solver *solver1, CacheManager *cacheManager1): ClientHandler(cacheManager1) {
        this->solver = solver1;
    }

    void handleClient(int sockID) override;
};


#endif //ALGOPROJECT_MYTESTCLIENTHANDLER_H
