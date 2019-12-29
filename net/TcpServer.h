#ifndef ETHAN_NET_TCPSERVER_H
#define ETHAN_NET_TCPSERVER_H

#include "EventLoop.h"

namespace ethan {

class TcpServer {
public:
    TcpServer() {}
    void run();
private:
    EventLoop loop;
};

}

#endif