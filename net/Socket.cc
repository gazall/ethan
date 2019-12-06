#include "Socket.h"
#include "AddrFactory.h"
#include "base/log_wrapper.h"
#include "base/Exception.h"
#include <sstream>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

using namespace ethan;

Socket::Socket(int family_, int type_, int protocol_) :
    family(family_), type(type_), protocol(protocol_) {
    fd = socket(family, type, protocol); 
    if (fd < 0) {
        throw Exception(strerror(errno));
    }
}

Socket::~Socket() {
    ::close(fd);
}

void Socket::bindAndListen(Address::ptr addr) {
    if (nullptr == addr) {
        throw Exception("localaddr is nullptr.");
    }

    localAddr = addr; 
    int ret = bind(fd, localAddr->getAddr(), localAddr->getAddrLen());
    if (ret < 0) {
        throw Exception(strerror(errno));
    }

    ret = listen(fd, SOMAXCONN);
    if (ret < 0) {
        throw Exception(strerror(errno));
    }
}

Socket::ptr Socket::accept() {
    int acceptFd = ::accept(fd, nullptr, nullptr);
    if (acceptFd < 0) {
        LOG_ERROR << strerror(errno);
        return nullptr;
    }

    Socket::ptr acceptPtr = std::make_shared<Socket>(family, type, protocol);
    acceptPtr->setFd(acceptFd);

    return acceptPtr;
}

bool Socket::connect(Address::ptr peer) {
    int ret = ::connect(fd, peer->getAddr(), peer->getAddrLen());
    if (ret < 0) {
        LOG_ERROR << strerror(errno);
        return false;
    }
    return true;
}

int Socket::send(const char *buf, size_t len, int flag) {
    int ret = ::send(fd, buf, len, flag);
    return ret;
}

int Socket::recv(char *buf, size_t len, int flag) {
    int ret = ::recv(fd, buf, len, flag);
    return ret;
}

void Socket::setAddrReuse() {

}

void Socket::setPortReuse() {

}


void Socket::setTcpNoDelay() {

}

