#include "Socket.h"
#include <sys/socket.h>
#include <sys/types.h>

using namespace std;

Socket::Socket(int family_, int type_, int protocol_) :
    family(family_), type(type_), protocol(protocol_) {
}

Socket::~Socket() {
    if (!isFdValid()) {
        return ;
    }

    ::close(fd);
}

void Socket::bindAndListen(Address::ptr addr) {
    fd = socket(family, type, protocol); 
    if (fd < 0) {
        throw  
    }

    localAddr = addr; 
    int ret = bind(fd, localAddr->getAddr(), localAddr->getAddrLen());
    if (ret < 0) {
        throw
    }

    ret = listen(fd, SOMAXCONN);
    if (ret < 0) {
        throw
    }
}

Socket::ptr Socket::accept() {

}

void Socket::connect() {

}

bool Socket::isFdValid() {

}

int Socket::send(const char *buf, size_t len, int flag = 0) {

}

int Socket::recv(char *buf, size_t len, int flag = 0) {

}

