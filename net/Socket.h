#ifndef ETHAN_NET_SOCKET
#define ETHAN_NET_SOCKET

#include <memory>
#include "Address.h"

namespace ethan {

/**
 *
 *server and client use the same Socket class
 *only for tcp
 */
class Socket : public enable_shared_from_this<Socket> {
public:
    typedef std::shared_ptr<Socket> ptr;
    typedef std::weak_ptr<Socket> weak_ptr;

    Socket(int family, int type, int protocol, Address::ptr address); 
    ~Socket();
    Socket(const Socket &other) = delete;
    Socket &operator=(const Socket &other) = delete;

    void listenAndBind();
    Socket::ptr accept();
    void connect();

    int send(const char *buf, size_t len, int flag = 0);
    int recv(char *buf, size_t len, int flag = 0);

    bool isConnected() {
        return isConnected;
    }
private:
    int fd; 
    int family;
    int type;
    int protocol;
    bool isConnected;
    Address::ptr localAddr; 
    Address::ptr remoteAddr; 
};

}

#endif
