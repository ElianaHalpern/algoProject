//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SERVER_H
#define ALGOPROJECT_SERVER_H
#include "ClientHandler.h"

using namespace std;

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler *clientHandler) = 0;

        virtual void stop() = 0;

        virtual bool accept() = 0;
    };
}

#endif //ALGOPROJECT_SERVER_H
