#ifndef ETHAN_NET_ADDRESS_
#define ETHAN_NET_ADDRESS_

#include <base/NoCopable.h>
#include <memory>
#include <string>
#include <sys/un.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

namespace ethan {

class Address : public NoCopable {
public:
    typedef std::shared_ptr<Address> ptr;
    virtual ~Address() {}

    int getFamily() const;
    virtual const sockaddr *getAddr() const = 0;
    virtual socklen_t getAddrLen() const = 0;

    bool operator<(const Address &a) const;
    bool operator==(const Address &a) const;
    bool operator>(const Address &a) const;
};

class IPv4Addr : public Address {
public:
    typedef std::shared_ptr<IPv4Addr> ptr;
    IPv4Addr(const std::string &addr = "0.0.0.0", uint16_t port = 0);

    sockaddr *getAddr() const override;
    socklen_t getAddrLen() const override;
    uint16_t getPort() const;
    void setPort(uint16_t);

private:
    sockaddr_in addr;
};

class IPv6Addr : public Address {
public:
    typedef std::shared_ptr<IPv6Addr> ptr;
    IPv6Addr(const std::string &addr = "0.0.0.0", uint16_t port = 0);

    sockaddr *getAddr() const override;
    socklen_t getAddrLen() const override;
    uint16_t getPort() const;
    void setPort(uint16_t);

private:
    sockaddr_in6 addr;
};

class UnixAddr : public Address {
public:
    typedef std::shared_ptr<UnixAddr> ptr;
    UnixAddr(const std::string &path);

    sockaddr *getAddr() const override;
    socklen_t getAddrLen() const override;

private:
    sockaddr_un addr;
    int length;
};

}
#endif
