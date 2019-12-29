#include "TcpServer.h"

namespace ethan {

void TcpServer::run() {
    loop.runEventLoop();
}

}