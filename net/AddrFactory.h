#include "Address.h"
#include <memory>

namespace ethan {
class AddrFactory {
public:
    static Address::ptr getAddr(Addr_Type type,const std::string &addr,
                                                        const uint16_t port) {
        switch (type) {
            case IPv4:
                return std::make_shared<IPv4Addr>(addr, port);
            break;
            case IPv6:
                return std::make_shared<IPv6Addr>(addr, port);
            break;
            case UNIX_SOCKET:
                return nullptr;
            break;
        }
    }
};
}