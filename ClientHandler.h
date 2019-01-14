//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_HANDLECLIENT_H
#define ALGOPROJECT_HANDLECLIENT_H
#include <iostream>
#include "CacheManager.h"

using namespace std;

class ClientHandler {
protected:
    CacheManager *cacheManager;

public:
    ClientHandler(CacheManager *cacheManager1) {
        this->cacheManager = cacheManager1;
    }

    virtual void handleClient(int SockID) = 0;
};

#endif //ALGOPROJECT_HANDLECLIENT_H
