#ifndef ETHAN_NET_SOCKETCTX_H
#define ETHAN_NET_SOCKETCTX_H

#include "Socket.h"
#include <memory>
#include <functional>

namespace ethan {

#define EVENT_NONE 0x0
#define EVENT_READ 0x01
#define EVENT_WRITE 0x02

using Event_Cb = std::function<void ()>;
class SocketCtx {
public:
    typedef std::shared_ptr<SocketCtx> ptr;

    explicit SocketCtx(Socket::ptr sock) {
        sockptr = sock;
    }
    Socket::ptr getSockPtr() const {
        return sockptr;
    }
    bool operator<(const SocketCtx &ctx) const {
        return sockptr->getFd() < ctx.getSockPtr()->getFd();
    }
    bool operator==(const SocketCtx &ctx) const {
        return sockptr->getFd() == ctx.getSockPtr()->getFd();
    }
    void addEvent(Event_Cb cb, int type);
    void delEvent(int type);

private:
    void setReadCb(Event_Cb cb) {
        rd_cb = cb;
    }
    void setWriteCb(Event_Cb cb) {
        wr_cb = cb;
    }
    void addEventType(int type) {
        events |= type;
    }
    void delEventType(int type) {
        events &= (~type); 
    }

private:
    //read callback
    Event_Cb rd_cb = nullptr;
    //write callback
    Event_Cb wr_cb = nullptr;

    Socket::ptr sockptr = nullptr;
    int events = EVENT_NONE;
};

}
#endif