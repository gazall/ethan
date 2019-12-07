#include "SocketCtx.h"
#include "base/log_wrapper.h"

namespace ethan {

void SocketCtx::addEvent(Event_Cb cb, int type) {
    if (cb == nullptr) {
        LOG_ERROR << "SocketCtx::addEvent, cb is null.";
        return;
    }
    if (type != EVENT_READ && type != EVENT_WRITE) {
        LOG_ERROR << "SocketCtx::addEvent, type : " << type;
        return ;
    }

    addEventType(type);
    if (type == EVENT_READ) {
        setReadCb(cb);
    }
    if (type == EVENT_WRITE) {
        setWriteCb(cb);
    }
}

void SocketCtx::delEvent(int type) {

}

}