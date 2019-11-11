#include "Address.h"
#include <string.h>

using namesapce ethan;

int Address::getFamily() const {
    return getAddr()->sin_family;
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
            memcmp(getAddr(), a.getAddr()) == 0;
}

bool Address::operator>(const Address &a) const {
    return !(*this < a); 
}

IPv4Addr::IPv4Addr(uint32_t addr, uint32_t port) {
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = addr;
    addr.sin_port = port;
}

sockaddr *IPv4Addr::getAddr() const {

}

socklen_t IPv4Addr::getAddrLen() const {
}

uint32_t IPv4Addr::getPort() const {
}

void IPv4Addr::setPort(uint32_t p) {
}

IPv6Addr::IPv6Addr(uint32_t addr, uint32_t port) {
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = addr;
    addr.sin_port = port;
}

sockaddr *IPv6Addr::getAddr() const {

}

socklen_t IPv6Addr::getAddrLen() const {
}

uint32_t IPv6Addr::getPort() const {
}

void IPv6Addr::setPort(uint32_t p) {
}

UnixAddr::UnixAddr(const std::string &path) {
}

sockaddr *UnixAddr::getAddr() const {

}

socklen_t UnixAddr::getAddrLen() const {

}
