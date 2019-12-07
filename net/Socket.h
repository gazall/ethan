#ifndef ETHAN_NET_SOCKET
#define ETHAN_NET_SOCKET

#include "Address.h"
#include <base/NoCopyable.h>
#include <memory>

namespace ethan {

/**
 *
 *server and client use the same Socket class
 *only for tcp
 */
class Socket : public std::enable_shared_from_this<Socket>
                , NoCopyable {
public:
    typedef std::shared_ptr<Socket> ptr;
    typedef std::weak_ptr<Socket> weak_ptr;

    //throw Exception when socket failed.
    Socket(int family, int type, int protocol); 
    ~Socket();

    void bindAndListen(Address::ptr localAddr);
    Socket::ptr accept();
    bool connect(Address::ptr peer);

    int send(const char *buf, size_t len, int flag = 0);
    int recv(char *buf, size_t len, int flag = 0);

    void setFd(int acceptFd) {
        fd = acceptFd;
    }
    int getFd() const {
        return fd;
    }

    void setLocalAddr(Address::ptr addr) {
        localAddr = addr;
    }
    void setPeerAddr(Address::ptr addr) {
        peerAddr = addr;
    }

    void setAddrReuse();
    void setPortReuse();
    void setTcpNoDelay();
private:
    int fd = -1; 
    int family = 0;
    int type = 0;
    int protocol = 0;
    Address::ptr localAddr = nullptr; 
    Address::ptr peerAddr = nullptr; 
};

}

#endif
