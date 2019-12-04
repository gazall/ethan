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
        std::stringstream ss;
        ss << "socket failed, " << strerror(strno) << "\n";
        throw Exception(ss.str());
    }
}

Socket::~Socket() {
    ::close(fd);
}

bool Socket::bindAndListen(Address::ptr addr) {
    localAddr = addr; 
    int ret = bind(fd, localAddr->getAddr(), localAddr->getAddrLen());
    if (ret < 0) {
        LOG_ERROR << strerror(errno);
        return ret;
    }

    ret = listen(fd, SOMAXCONN);
    if (ret < 0) {
        LOG_ERROR << strerror(errno);
        return ret;
    }

    return true;
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

bool Socket::connect() {

}

bool Socket::isFdValid() {

}

int Socket::send(const char *buf, size_t len, int flag) {

}

int Socket::recv(char *buf, size_t len, int flag) {

}

