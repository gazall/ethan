#ifndef ETHAN_NET_SOCKET
#define ETHAN_NET_SOCKET

#include "Address.h"
#include <base/NoCopable.h>
#include <memory>

namespace ethan {

/**
 *
 *server and client use the same Socket class
 *only for tcp
 */
class Socket : public std::enable_shared_from_this<Socket>
                , NoCopable {
public:
    typedef std::shared_ptr<Socket> ptr;
    typedef std::weak_ptr<Socket> weak_ptr;

    Socket(int family, int type, int protocol); 
    ~Socket();

    bool bindAndListen(Address::ptr localAddr);
    Socket::ptr accept();
    bool connect();

    int send(const char *buf, size_t len, int flag = 0);
    int recv(char *buf, size_t len, int flag = 0);

    void setFd(int acceptFd) {
        fd = acceptFd;
    }

    bool isFdValid();

    bool isConnected() {
        return isConnect;
    }
private:
    int fd = -1; 
    int family = 0;
    int type = 0;
    int protocol = 0;
    bool isConnect = false;
    Address::ptr localAddr = nullptr; 
    Address::ptr remoteAddr = nullptr; 
};

}

#endif
