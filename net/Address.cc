#include "Address.h"
#include <string.h>
#include <arpa/inet.h>
#include <stddef.h>

using namespace ethan;

int Address::getFamily() const {
    return getAddr()->sa_family;
}

bool Address::operator<(const Address &a) const {
    int minLen = std::min(getAddrLen(), a.getAddrLen());
    int ret = memcmp(getAddr(), a.getAddr(), minLen);
    if (ret < 0) {
        return true;
    } else if (ret >0) {
        return false;
    } else if (getAddrLen() < a.getAddrLen()) {
        return true;
    }
    return false;
}

bool Address::operator==(const Address &a) const {
    return getAddrLen() == a.getAddrLen() &&
            memcmp(getAddr(), a.getAddr(), getAddrLen()) == 0;
}

bool Address::operator>(const Address &a) const {
    return !(*this < a); 
}

IPv4Addr::IPv4Addr(const std::string &addr_, uint16_t port_) {
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(addr_.c_str());
    addr.sin_port = htonl(port_);
}

sockaddr *IPv4Addr::getAddr() const {
    return (sockaddr *)(&addr);
}

socklen_t IPv4Addr::getAddrLen() const {
    return sizeof(addr);
}

uint16_t IPv4Addr::getPort() const {
}

void IPv4Addr::setPort(uint16_t p) {
}

IPv6Addr::IPv6Addr(const std::string &addr_, uint16_t port_) {
    memset(&addr, 0, sizeof(addr));
    addr.sin6_family = AF_INET6;
    memcpy(&addr.sin6_addr.s6_addr, addr_.c_str(), sizeof(addr.sin6_addr.s6_addr));
    addr.sin6_port = htons(port_);
}

sockaddr *IPv6Addr::getAddr() const {
    return (sockaddr *)(&addr);
}

socklen_t IPv6Addr::getAddrLen() const {
    return sizeof(addr);
}

uint16_t IPv6Addr::getPort() const {
}

void IPv6Addr::setPort(uint16_t p) {
}

UnixAddr::UnixAddr(const std::string &path) {
   memset(&addr, 0, sizeof(addr)); 

   addr.sun_family = AF_UNIX;
   int len = std::min(path.size(), sizeof(addr.sun_path));
   memcpy(addr.sun_path, path.c_str(), len);
   length = offsetof(sockaddr_un, sun_path) + strlen(addr.sun_path) + 1;
}

sockaddr *UnixAddr::getAddr() const {
    return (sockaddr *)(&addr);
}

socklen_t UnixAddr::getAddrLen() const {
    return length;
}
